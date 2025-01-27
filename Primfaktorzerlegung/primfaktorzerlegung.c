#include <stdio.h>
#include <stdlib.h>

// ohne Zusatzaufgabe
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Error, bitte gib genau eine Zahl an!");
        return 1;
    }

    int n = atoi(argv[1]);
    if(n == 1 || n == 0)
    {
        printf("%d\n", n );
        return 0;
    }
    for(int i = 2; n != 1; i++)
    {
        if(n % i == 0)
        {
            printf("%d\n", i);
            n /= i;
            i--;
        }
    }
    return 0;
}