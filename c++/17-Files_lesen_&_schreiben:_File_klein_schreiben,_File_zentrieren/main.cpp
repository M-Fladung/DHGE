#include <iostream>
#include <cctype>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cerr << "Error: Parameter werden benötigt <file1><file2>";
        exit(EXIT_FAILURE);
    }
    ifstream inf(argv[1]);
    if(!inf)
    {
        cerr << "Fehler beim öffnen von file1";
        exit(EXIT_FAILURE);
    }

    ofstream outf(argv[2]);
    if(!outf)
    {
        cerr << "Fehler beim öffnen von file2";
        exit(EXIT_FAILURE);
    }
    char c;

    while(inf.get(c))
    {
        if(!(outf.put(tolower(c)))) {
            cerr << "Fehler beim schreiben in file 2";
            exit(EXIT_FAILURE);
        }
    }
    inf.close();
    outf.close();

    exit(EXIT_SUCCESS);
}