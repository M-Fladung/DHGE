#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

const char *programmName;

void errmsg()
{

} 

int main(int argc, char *argv[])
{
    FILE *infile, *outfile;
    if(argc >= 4)
    {
    programmName = argv[0];
    fprintf("Error in %s, ausgabe[wort*][wort*][file][file] ", programmName);
     exit(EXIT_FAILURE);   
    }
}