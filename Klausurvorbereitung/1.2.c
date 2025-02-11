#include <stdio.h>
#include <stdlib.h>

int secondcounter;

int counter(void)
{
    static int val = 0;
    val++;
    secondcounter++;
    secondcounter++;
    printf("%d", secondcounter);
}



int main(int argc, char *argv[])
{
    counter();
    counter();
    counter();
    counter();
    
    exit(EXIT_SUCCESS);
}