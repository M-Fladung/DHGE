#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wuerfeln()
{
    int previous_number = 0, current_number = 0;
    int j;
    for(int i = 1; !(previous_number == 6 && current_number == 6); i++) // Vorrangsregeln: Negation würde ohne Klammern zuerst analysiert
    {
        previous_number = current_number;
        current_number = rand() % (6 + 1);
        j = i+1;
    }
    //
    printf("%d\n", j);
    return j;
}

int main(int argc)
{
    if(argc != 1)
    {
        fprintf(stderr, "Error, bitte ausnahmsweise nichts mit angeben");
        return 1;
    }
    srand(time(NULL));
    clock_t start = clock(); // Startzeit messen
    int max = 0, min = 10000;
    double numbers_add = 0;
    for(int i = 0; i < 100000; i++)
    {
        int var = wuerfeln();
        if(var > max) {max = var;}
        if(var < min) {min = var;}
        numbers_add += var;
    }
        clock_t end = clock(); // Endzeit messen

    // Berechnung der Laufzeit
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Laufzeit: %.6f Sekunden\n", elapsed_time);

    double avg = numbers_add / 100000;
    printf("Durchschnitt: %f, MAX: %d, MIN, %d\n", avg, max, min);
    return 0;
    
}