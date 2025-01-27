#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char *hexnumber = argv[1];
    int decimalnumber = 0;
    for(int i = 0; hexnumber[i] != '\0'; i++)
    {
        //65 = 10 66 = 11 ...
        //auf ASCII achten
        if(hexnumber[i] >= 48 && hexnumber[i] <= 57)
        {
            decimalnumber += hexnumber[i] - '0';
        }else if(hexnumber[i] >= 97 && hexnumber[i] <= 102){
            char hexindec = hexnumber[i] - 49;
            decimalnumber += hexindec - '0'; 
            decimalnumber += 10;
        }else if(hexnumber[i] >= 65 && hexnumber[i] <= 70){
            hexnumber[i] = hexnumber[i] + 32;
            i--;
        }else{
            fprintf(stderr,"Error, bitte gib eine Hexadezimalzahl an!");
            return 1;
        }
        
    }
    printf("Number = %d\n", decimalnumber);
    return 0;
}