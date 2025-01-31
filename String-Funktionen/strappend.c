#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *strappend(char *dest, const char *src);
char *strappend(char *dest, const char *src)
{
    char *destEnd = dest;
    for(; *destEnd != '\0'; destEnd++);
    for(const char *srcPtr = src; *srcPtr != '\0'; srcPtr++)
    {
        *destEnd = *srcPtr;
        destEnd++;
    }
    *destEnd = '\0';
    return dest;
}

int main(int argc, char *argv[])
{
    //char *dest = malloc(sizeof(argv[1] + 1));

    printf("%s\n", strappend(argv[1], argv[2]));
}