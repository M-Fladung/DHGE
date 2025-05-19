#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[])
{
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    double result = (double) (num1*num2);
    printf("%f", result);
}