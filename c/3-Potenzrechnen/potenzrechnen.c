#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// beim Kompilieren muss lm noch mit angegeben werden um math.h zu verlinken --> "gcc potenzrechnen.c -o potenzrechnen -lm" 

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Error, Bitte gib genau 2 Parameter in %s an\n", argv[0]);
        return 1;
    }
    int result = 1;
    printf("Bitte gib erst den Nenner und dann die Potenz an\n");
    for( int i = 0; i < atof(argv[1]); i++) // pow beispiel
    {
        result = atof(argv[2]) * result;
        
    }
    //float result = pow(atof(argv[1]), atof(argv[2]));
    printf("Die Potenz deiner Eingaben ist: %d\n", result);
    return 0;
}