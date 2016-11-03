#include <stdio.h>
#include <stdlib.h>

double cube(double);
double quad(double);

int main(int argc, char* argv[]) {
    double a = (argv[1]) ? atof(argv[1]) : 16;
    printf("Cube: %.2f\nQuad: %.2f\n", cube(a), quad(a));
    return 0;
}