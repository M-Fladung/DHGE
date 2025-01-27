#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to convert string to integer (like atoi)
int string_to_int(const char *str) {
    int result = 0;
    int sign = 1;

    // Check for a leading '-' for negative numbers
    if (*str == '-') {
        sign = -1;
        str++;
    }

    // Process each character in the string
    while (*str) {
        if (!isdigit(*str)) {
            printf("Error: Invalid character '%c' in input string.\n", *str);
            return result * sign;
        }
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

// Function to convert integer to string
char *int_to_string(int value, char *result, size_t max_len) {
    if (max_len <= 0) {
        return NULL;
    }

    size_t index = 0;
    int is_negative = 0;

    // Handle negative numbers
    if (value < 0) {
        is_negative = 1;
        value = -value;
    }

    // Extract digits and store them in reverse order
    do {
        if (index >= max_len - 1) {
            return NULL; // Overflow
        }
        result[index++] = (value % 10) + '0';
        value /= 10;
    } while (value > 0);

    // Add negative sign if necessary
    if (is_negative) {
        if (index >= max_len - 1) {
            return NULL; // Overflow
        }
        result[index++] = '-';
    }

    // Null-terminate the string
    result[index] = '\0';

    // Reverse the string
    for (size_t i = 0, j = index - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numbers as strings>\n", argv[0]);
        return 1;
    }

    char result[10];

    for (int i = 1; i < argc; i++) {
        // Convert string to integer
        int num = string_to_int(argv[i]);

        // Convert back to string
        if (int_to_string(num, result, sizeof(result))) {
            printf("Original: %s, Integer: %d, Back to String: %s\n", argv[i], num, result);
        } else {
            printf("Error: Overflow while converting number %d back to string.\n", num);
        }
    }

    return 0;
}
