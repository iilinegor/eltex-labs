#include <stdio.h>

double cube(double);
double quad(double);

int main() {
    double a = 16;
    printf("cube: %.0f\nquad: %.0f\n", cube(a), quad(a));
    return 0;
}