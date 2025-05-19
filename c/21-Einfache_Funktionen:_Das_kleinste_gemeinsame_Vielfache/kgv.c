#include <stdio.h>
#include <stdlib.h>

int kgv(int a,int b)
{
    int vielfachesA, vielfachesB;
    if(a == 0 || b == 0)
    {
        return 0;
    }else if (a < 0)
    {
        a = -a;
    }else if (b < 0)
    {
        b = -b;
    };

    vielfachesA = a;
    vielfachesB = b;

    while(vielfachesA != vielfachesB)
    {
        if(vielfachesA < vielfachesB){
            vielfachesA += a;
        }else{
            vielfachesB += b;
        }
    }
    return vielfachesA;
    
    
}

int main(int argc, char *argv[])
{
    int a,b;
    printf("Bitte geben Sie Zahl 1 und 2 für das kgv ein.");
    scanf("%d", &a);
    scanf("%d", &b);
    int result = kgv(a,b);
    printf("Das kleinste gemeinsame Vielfache lautet: %d\n", result);
}