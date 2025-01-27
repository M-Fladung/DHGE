#include <stdio.h>
#include <stdlib.h>


int minmax(double numbers[], int length, double *max, double *min)
{
    if (length <= 0) 
    {
        return -1; // Fehler: Leeres Array
    }

    *max = numbers[0];
    *min = numbers[0];
    for(int i = 1; i < length; i++)
    {
        if(numbers[i] > (*max)) *max = numbers[i];
        if(numbers[i] < (*min)) *min = numbers[i];
    }
    return 0;
}

int main(int argc, char *argv[])
{
    double num[argc - 1];
    double max, min;

    for(int i = 1; i < argc; i++)
    {
        num[i - 1] = atof(argv[i]);
    }

    minmax(num, (argc - 1), &max, &min);
    printf("Max: %f, Min %f\n", max, min);
    return 0;
}