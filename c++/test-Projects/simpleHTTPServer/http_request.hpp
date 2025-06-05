#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // 1. Socket erstellen
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket fehlgeschlagen");
        exit(EXIT_FAILURE);
    }

    // 2. Socket-Optionen setzen
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // 3. Adresse binden
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    // 4. Warten auf Verbindungen
    listen(server_fd, 3);
    std::cout << "Server läuft auf http://localhost:" << PORT << "\n";

    // 5. Verbindung annehmen und antworten
    while ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) >= 0) {
        char buffer[3000] = {0};
        read(new_socket, buffer, 3000);

        std::string request(buffer);
        std::cout << "Anfrage erhalten:\n" << request << "\n";

        std::string response_body = "<h1>Hallo von deinem eigenen HTTP-Server!</h1>";
        std::stringstream response;
        response << "HTTP/1.1 200 OK\r\n"
                 << "Content-Type: text/html\r\n"
                 << "Content-Length: " << response_body.length() << "\r\n"
                 << "Connection: close\r\n"
                 << "\r\n"
                 << response_body;

        send(new_socket, response.str().c_str(), response.str().length(), 0);
        close(new_socket);
    }

    return 0;
}
