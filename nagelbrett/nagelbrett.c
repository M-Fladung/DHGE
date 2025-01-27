#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Verwendung: %s <Anzahl der Reihen> <Anzahl der Kugeln>\n", argv[0]);
        return 1;
    }

    int r = atoi(argv[1]);
    int k = atoi(argv[2]);

    if (r <= 0 || k <= 0)
    {
        fprintf(stderr, "Fehler: Die Anzahl der Reihen und Kugeln muss positiv sein!\n");
        return 1;
    }

    int facher = r + 1;
    int counts[facher];
    for (int i = 0; i < facher; i++)
    {
        counts[i] = 0;
    }

    srand(time(NULL));

    // Kugeln simulieren
    for (int i = 0; i < k; i++)
    {
        int position = 0;

        for (int j = 0; j < r; j++)
        {
            position += rand() % 2;
        }

        counts[position]++;
    }

    int max_count = 0;
    for (int i = 0; i < facher; i++)
    {
        if (counts[i] > max_count)
        {
            max_count = counts[i];
        }
    }

    int zeilenlaenge = 50;
    double faktor = (double)zeilenlaenge / max_count;

    printf("Ergebnis des Nagelbrett-Versuchs:\n\n");
    for (int i = 0; i < facher; i++)
    {
        printf("%3d: ", counts[i]);
        int balkenlaenge = (int)(counts[i] * faktor);
        for (int j = 0; j < balkenlaenge; j++)
        {
            putchar('#');
        }
        putchar('\n');
    }

    return 0;
}
