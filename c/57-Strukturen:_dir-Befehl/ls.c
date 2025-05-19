#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>

const char *progname;

void errMsg(const char *Msg, const char *file);
int listall(const char *currentfolder, DIR *d);
int listwithinfo(const char *currentfolder, DIR *d);

int listwithinfo(const char *currentfolder, DIR *d)
{
    struct stat fileStatistics;
    while (1)
    {
        errno = 0;
        struct dirent *entry = readdir(d);
        if (entry == NULL)
            break;
        if (stat(entry->d_name, &fileStatistics) != 0)
        {
            errMsg("Informationen über Dateien", currentfolder);
        }

        char typ = S_ISREG(fileStatistics.st_mode) ? 'f' :S_ISDIR(fileStatistics.st_mode) ? 'd' : '?';
        char *date = ctime(&(fileStatistics.st_mtime));
        *(strchr(date, '\n')) = '\0';
        printf("%ld  %c  %s  %s\n", fileStatistics.st_size, typ, date, entry->d_name);
    }
    return 0;
}
int listall(const char *currentfolder, DIR *d)
{
    if (d == NULL)
    {
        errMsg("Dateizugriff", currentfolder);
    }
    while (1)
    {
        errno = 0;
        struct dirent *entry = readdir(d);
        if (entry == NULL)
        {
            break;
        }
        printf("%s\n", entry->d_name);
    }
    if (errno != 0)
    {
        errMsg("Verzeichniss aufrufen", currentfolder);
    }
    if (closedir(d) == -1)
    {
        errMsg("Verzeichnis schließen", currentfolder);
    }

}
void errMsg(const char *Msg, const char *file)
{
    fprintf(stderr, "%s: ERROR %s in %s: %s\n", progname, Msg, file, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    progname = argv[0];
    if (argc > 3)
    {
        errMsg("Dateiaufruf", progname);
    }

    const char currentfolder[] = ".";
    DIR *d = opendir(currentfolder);

    if (argc == 1)
    {
        listall(currentfolder, d);
    }

    if (strcmp(argv[0], "-a"))
    {
        listwithinfo(currentfolder, d);
    }

    if()

    exit(EXIT_SUCCESS);
}