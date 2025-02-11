#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    for(int i = argc-1; i > 0; i--)
    {
        printf("%s, ", argv[i]);
    }
    printf("\n");
    int i = atoi(argv[1]);
    float f = atof(argv[2]);
    float sum = i + f; 
    printf("Summe: %f", sum);
    exit(EXIT_SUCCESS);
}