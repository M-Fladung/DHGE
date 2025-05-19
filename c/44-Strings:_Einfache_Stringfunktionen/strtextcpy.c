#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *strtextcpy(char *dest, const char *src);

char *strtextcpy(char *dest, const char *src)
{
    char *startdest = dest;
    for (const char *currptr = src; *currptr != '\0'; currptr++)
    {
        if (!isspace(*currptr))
        {
            *startdest = *currptr;
            startdest++;
        }
    }

    *startdest = '\0';
    return dest;
}

int main(int argc, char *argv[])
{
    char *myarr = malloc(sizeof(argv[1]) + 1);
    printf("%s\n", strtextcpy(myarr, argv[1]));
    free(myarr);
    exit(EXIT_SUCCESS);
}