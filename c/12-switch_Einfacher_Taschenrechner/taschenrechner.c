#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{

    if ((argc - 1) % 2 == 0)
    {
        fprintf(stderr, "Ungültige Anzahl von Eingabewörtern!\n");
        fprintf(stderr, "Verwendung: <Zahl> <Operator> <Zahl> ...\n");
        return 1;
    }

    double result = atof(argv[1]);

    for (int i = 2; i < argc; i += 2)
    {
        char operator= argv[i][0];
        double operand = atof(argv[i + 1]);

        switch (operator)
        {
        case '+':
            result += operand;
            break;
        case '-':
            result -= operand;
            break;
        case 'x':
            result *= operand;
            break;
        case '/':
            if (operand == 0)
            {
                fprintf(stderr, "Fehler: Division durch 0 ist nicht erlaubt!\n");
                return 1;
            }
            result /= operand;
            break;
        case 'p':
            result = pow(result, operand);
            break;
        default:
            fprintf(stderr, "Fehler: Ungültiges Rechenzeichen '%c'!\n", operator);
            return 1;
        }
    }

    printf("Ergebnis: %.2f\n", result);
    return 0;
}
