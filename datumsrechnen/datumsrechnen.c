#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("Usage: %s <day> <month> <year>\n", argv[0]);
        return 1;
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]) - 1;
    int year = atoi(argv[3]) - 1900;

    struct tm time_info = {0};
    time_info.tm_mday = day;
    time_info.tm_mon = month;
    time_info.tm_year = year;
    time_info.tm_hour = 12;
    time_info.tm_min = 0;
    time_info.tm_sec = 0;
    time_info.tm_isdst = -1;

    time_t raw_time = mktime(&time_info);

    if (raw_time == -1)
    {
        printf("Error: Invalid date.\n");
        return 1;
    }

    struct tm *local_time = localtime(&raw_time);

    const char *weekdays[] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

    printf("Der %d.%d.%d (%d. Tag des Jahres) ist ein %s.\n",
           time_info.tm_mday, time_info.tm_mon + 1, time_info.tm_year + 1900,
           local_time->tm_yday + 1, weekdays[local_time->tm_wday]);

    return 0;
}
