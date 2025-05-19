#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
const char *progName;

void errMsg(const char *operation, const char *fileName)
{
  fprintf(stderr, "%s: error %s %s: %s\n",
          progName, operation, fileName, strerror(errno));
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    progName = argv[0];
    const char *filenameIN = argv[1];
    const char *filenameOUT = argv[2];
    FILE *inFile, *outFile;

    int c, n, max = 0;
    inFile = fopen(filenameIN, "r");
    outFile = fopen(filenameOUT, "w");
    while ((c = fgetc(inFile)) != EOF)
    {
        if (isspace(c))
        {
            if (n == 0)
            {
                putc(c, outFile);
            }
            else
            {
            }
            n++;
            if (n > max)
            {
                max = n;
            }
        }
        else
        {
            putc(c, outFile);
            n = 0;
        }
    }
    exit(EXIT_SUCCESS);
}