#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ops.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Wrong invocation\n\n");
        printf("Usage: ./calc <operation> <num1> <num2>\n");
        return 1;
    }

    const char* op = argv[1];
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    int result = -1;
    if (strcmp(op, "add") == 0) {
        printf("Adding the numbers %i, %i\n", num1, num2);
        result = add(num1, num2);
    } else if (strcmp(op, "subtract") == 0) {
        printf("Subtracting the numbers %i, %i\n", num1, num2);
        result = subtract(num1, num2);
    } else if (strcmp(op, "multiply") == 0) {
        printf("Multiplying the numbers %i, %i\n", num1, num2);
        result = multiply(num1, num2);
    } else if (strcmp(op, "divide") == 0) {
        printf("Dividing the numbers %i, %i\n", num1, num2);
        result = divide(num1, num2);
    } else {
        fprintf(stderr, "Unkown operation %s. Exiting...\n", op);
        return 1;
    }

    printf("Result: %i\n", result);

    return 0;
}