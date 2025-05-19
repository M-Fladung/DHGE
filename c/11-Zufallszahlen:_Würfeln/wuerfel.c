#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc)
{
    if(argc != 1)
    {
        fprintf(stderr, "Error, bitte ausnahmsweise nichts mit angeben");
        return 1;
    }
    //int wiederholungen = 10;
    srand(time(NULL));
    int previous_number = 0, current_number = 0;
    for(int i = 1; !(previous_number == 6 && current_number == 6); i++) // Vorrangsregeln: Negation würde ohne Klammern zuerst analysiert
    {
        previous_number = current_number;
        current_number = rand() % (6 + 1);
        printf("Wurf %d hat als Ergebnis: %d und davor %d\n", i, previous_number, current_number);
    }
    printf("Wurf hat als Ergebnis: %d und davor %d\n", previous_number, current_number);
}