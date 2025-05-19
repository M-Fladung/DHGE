#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Funktion: my_strtol
int my_strtol(const char *str, char **endptr) {
    const char *ptr = str; // Pointer zum Durchlaufen des Strings
    int result = 0;        // Ergebnis
    int sign = 1;          // Vorzeichen (1 für positiv, -1 für negativ)

    // Vorzeichen prüfen
    if (*ptr == '-') {
        sign = -1; // Negatives Vorzeichen
        ptr++;     // Pointer weiterbewegen
    }

    // Schleife durch die Ziffern
    while (isdigit((unsigned char)*ptr)) {
        result = result * 10 + (*ptr - '0'); // Ziffer zum Ergebnis hinzufügen
        ptr++;                              // Pointer weiterbewegen
    }

    // Endpointer setzen, wenn nicht NULL
    if (endptr) {
        *endptr = (char *)ptr; // Pointer auf das erste nicht verarbeitete Zeichen
    }

    return result * sign; // Ergebnis mit Vorzeichen zurückgeben
}

// Hauptprogramm
int main(int argc, char *argv[]) {
    // Prüfen, ob Argumente übergeben wurden
    if (argc < 2) {
        printf("Verwendung: %s <Werte>\n", argv[0]);
        return 1;
    }

    // Verarbeitung der Argumente
    for (int i = 1; i < argc; i++) {
        char *endptr = NULL; // Pointer für den verbleibenden Text
        int value = my_strtol(argv[i], &endptr);

        // Ergebnis ausgeben
        printf("Eingabe: %s\n", argv[i]);
        printf("Zahl: %d\n", value);

        // Überprüfen, ob der Pointer auf das Ende zeigt
        if (*endptr == '\0') {
            printf("Kein verbleibender Text.\n");
        } else {
            printf("Verbleibender Text: %s\n", endptr);
        }

        printf("\n");
    }

    return 0;
}
