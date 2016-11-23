#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inp_str(char*);
//void out_str(char* string, int length, int number);

int inp_str(char* string) {
    return (int)(strlen(string));
}

int campstr(const void *a, const void *b) {
    return (inp_str((char*)b) - inp_str((char*)a));
}

int main(int argc, char* argv[]) {
    int i = 0;
    char asd[255][10];

    for (i = 0; i < 5; scanf("%s", asd[i++]));

    qsort(asd, 5, sizeof(asd[0]), campstr);
    printf("\n");
    for (i = 0; i < 5; printf("%s %d\n", asd[i++], inp_str(asd[i])));
    return 0;
}