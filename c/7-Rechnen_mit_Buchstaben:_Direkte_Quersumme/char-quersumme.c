#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) // gibt eine Zahl z.B. 3425 ein und berechnet die Quersumme
{
    if (argc != 2)
    {
        fprintf(stderr, "Error, Bitte gib nur eine Zahl ein!\n");
        return 1;
    }

    int quersumme = 0;
    char *zahl = argv[1];
    
    for (int i = 0; zahl[i] != '\0'; i++)
    {
        
        if (zahl[i] < '0' || zahl[i] > '9') 
        {
            fprintf(stderr, "Error, Bitte gib nur eine gültige Zahl ein!\n");
            return 1;
        }
        printf("%d\n", zahl[i]); // zeigt die ASCII Werte an
        quersumme += zahl[i] - '0'; //convert to int and add
    }


    printf("Die Quersumme ist %d\n", quersumme);

    return 0;
}
