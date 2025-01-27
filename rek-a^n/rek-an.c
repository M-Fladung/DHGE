#include <stdio.h>
#include <stdlib.h>
//sqrt
float calc(float a, int n);

int main(int argc, char *argv[])
{
    int b;
    float a;
    printf("Bitte geben Sie zum potenzieren einen float und dann einen int an");
    scanf("%f", &a);
    scanf("%d", &b);
    int result = calc(a,b);
    printf("Die Potenz lautet: %d\n", result);
}

float calc(float a, int n)
{
    if(n == 0)
    {
        return 1;
    }else if (n < 0)
    {
        return 1/calc(a, -n);
    }else if (n % 2 == 0) //gerade
    {
        return calc(a*a, n/2);
    }else if (n % 2 != 0) //ungerade
    {
        return a * calc(a, n-1);
    }
    return 1;
    
    
}