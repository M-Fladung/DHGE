#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(argv[1][i] > 57 || argv[1][i] < 48)
        { 
            
            printf("Does not only contain numbers\n"); break;}
    }

}