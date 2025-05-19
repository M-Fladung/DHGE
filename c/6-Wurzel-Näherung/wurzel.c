#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double zahl, naehrung, urspruengliche_zahl;
    zahl = atof(argv[1]);
    int schritte = 0;

    //nicht sehr deppensicher
    if (zahl < 0) {
        printf("Ungültige Eingabe! Bitte nur positive Zahlen\n");
        return 1;
    }

    urspruengliche_zahl = zahl;
    naehrung = zahl;


    while (fabs(naehrung * naehrung - urspruengliche_zahl) >= urspruengliche_zahl * 1e-10) {
        naehrung = (naehrung + urspruengliche_zahl / naehrung) / 2.0;
        schritte++;
        printf("Schritt %d: Näherung = %.15f\n", schritte, naehrung);
    }

    double result = sqrt(zahl);
    printf("\nBerechnete Quadratwurzel: %.15f\n", naehrung);
    printf("\nDas Ergebnis mit sqrt lautet %.15f\n", result);
    printf("Anzahl der Schritte: %d\n", schritte);

    return 0;
}
