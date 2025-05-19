# include <stdio.h>
# include <stdlib.h> //für konvertierung von String in double

int main(int argc, char *argv[])
{
    // Fehler wenn keine Parameter mit angegeben
    if(argc == 1)
    {
        fprintf(stderr, "Error, in %s bitte geben Sie Parameter mit an.\n", argv[0]);
        return 1;
    }
    double num = 0;

    // addiere alle Parameter zusammen
    for(int i = 0; i < argc; i++)
    {
        num = num + atof(argv[i]);
    }
    printf("%d\n", argc); // index 0 von argv ist der Dateiname --> https://www.c-howto.de/tutorial/funktionen-teil-2/hauptfunktion/
    printf("Deine Eingaben addiert lauten: %f\n", num);
    printf("Der Mittelwert deiner Zahlen lautet: %f\n", num / (argc - 1 ));
    return 0;

}