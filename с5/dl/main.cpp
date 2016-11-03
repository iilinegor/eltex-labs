#define filename "./libmy.so"

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

double (*fptr)(double);
double quad(double);

int main(int argc, char* argv[]) {
    double a = (argv[1]) ? atof(argv[1]) : 16.0;
	void *dl = dlopen (filename, RTLD_LAZY);
	if (!dl)
		printf("asdasd\n");

	printf("%p\n", (double(*)(double)) dlsym(dl, "cube"));
	double (*fptr)(double) = NULL;
	fptr =  (double(*)(double)) dlsym(dl, "cube");
	// double c = (double) (* dlsym(dl, "cube"))(12);
	printf("%p\n", &fptr);
	// double q = (fptr)(3);//
    printf("Cube: %.2f\nQuad: %.2f\n", (*fptr)(12.4), 12.3);

    dlclose(dl);
    return 0;
}