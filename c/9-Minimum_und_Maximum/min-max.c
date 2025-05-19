#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error, bitte gib 2 oder mehr Zahlen an!\n");
        return 1;
    }

    int pos_pos = 1;
    int pos_neg = 1;

    int min = atoi(argv[1]);
    int max = atoi(argv[1]);

    for (int i = 2; argv[i] ; i++) {
        int current_number = atoi(argv[i]);
        if (current_number > max) {
            max = current_number;
            pos_pos = atoi(argv[i - 1]);
        }
        if (current_number < min) {
            min = current_number;
            pos_neg = atoi(argv[i]);
        }
    }

    printf("Zahl max: %d Position max: %d\n", max, pos_pos);
    printf("Zahl min: %d Position min: %d\n", min, pos_neg);

    return 0;
}
