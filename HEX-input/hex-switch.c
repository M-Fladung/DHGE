#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *hexnumber = argv[1];
    int decimalnumber = 0;

    for (int i = 0; hexnumber[i] != '\0'; i++) {
        switch (hexnumber[i]) {
            case '0' ... '9': // Zahlen 0-9
                decimalnumber += hexnumber[i] - '0';
                break;
            case 'a' ... 'f': // Kleinbuchstaben a-f
                decimalnumber += hexnumber[i] - 'a' + 10;
                break;
            case 'A' ... 'F': // Großbuchstaben A-F
                decimalnumber += hexnumber[i] - 'A' + 10;
                break;
            default: // Ungültige Zeichen
                fprintf(stderr, "Error, bitte gib eine Hexadezimalzahl an!");
                return 1;
        }
    }

    printf("Number = %d\n", decimalnumber);
    return 0;
}
