#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    // abs gibt wandelt Eingabe in positive Zahlen um.
    int a = abs(atoi(argv[1])); 
    int b = abs(atoi(argv[2]));
    double rest = 0;
    if(argc != 3) // Error, wenn weniger oder mehr als 2 Zahlen mitgegeben werden.
    {
        fprintf(stderr, "Error, bitte gib genau 2 Zahlen mit!!!\n");
        return 1;
    }
    if(b == 0 || a == 0) // Error, wenn eine Zahl 0 ist.
    {
        fprintf(stderr, "Error, keine deiner Zahlen darf 0 sein!!!\n");
        return 1;
    }
    while(b != 0)
    {
        rest = a % b;
        a = b;
        b = rest; 
    }
    printf("Der GGT zwischen %s und %s ist %d\n", argv[1], argv[2], a);
    return 0;
}