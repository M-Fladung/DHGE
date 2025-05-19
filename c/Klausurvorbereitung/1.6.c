#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char *argv[])
{
    int myarr[10];
    srand(time(NULL));
    
    for(int i = 0; i < 10; i++)
    {
        myarr[i] = rand() % 201 - 100;
    }
    for(int i = 0; myarr[i] != NULL; i++)
    {
        printf("%d", myarr[i]);
    }
}