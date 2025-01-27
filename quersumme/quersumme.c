#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Error, Bitte gib nur eine Zahl ein!");
        return 1;
    }

    long long fullnumber = atoll(argv[1]);
    long long temp = fullnumber;
    int length;
    while (temp > 0) 
    {
    length++;
    temp /= 10;
    }
    int digits[length];
    for (int i = length - 1; i >= 0; i--) {
        digits[i] = fullnumber % 10;   
        fullnumber /= 10;              
    }

    int result = 0;
    for (int i = 0; i < length; i++) {
        result += digits[i];
    }
    printf("Die Quersumme der Zahl ist: %d\n", result);
    return 0;
}