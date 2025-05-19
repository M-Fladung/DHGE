#include <stdio.h>
#include <stdlib.h>

int getlength(long long fullnumber)
{
    int length = 0;
    long long temp = fullnumber;
    while (temp > 0)
    {
        length++;
        temp /= 10;
    }
    return length;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error, Bitte gib nur eine Zahl ein!");
        return 1;
    }

    long long fullnumber = atoll(argv[1]);
    // for(int i = 0; fullnumber % 10 == 0; i++)
    int iteration = 0;
    while (fullnumber >= 10)
    {
        iteration++;
        int num = fullnumber; 
        int length = getlength(fullnumber);
        int digits[length];
        for (int i = length - 1; i >= 0; i--)
        {
            digits[i] = fullnumber % 10;
            fullnumber /= 10;
        }

        int result = 0;
        for (int i = 0; i < length; i++)
        {
            result += digits[i];
        }
        printf("Die Quersumme der Zahl %d ist: %d\n", num, result);
        fullnumber = result;
    }
    printf("Ende erreicht\n");
    return 0;
}