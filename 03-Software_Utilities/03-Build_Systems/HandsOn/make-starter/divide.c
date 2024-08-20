#include "ops.h"

int divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Divider cannot be Zero!\n");
        exit(1);
    }
    return a / b;
}