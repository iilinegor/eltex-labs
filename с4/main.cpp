#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <iostream>



int main(int argc,char* argv[]) {
    int i = 0;
    char line[255];

    char ar[255][3] = {"asdasd", "/home/iilinegor/ClionProjects/lab4/text.in", "f"};

    FILE *fp;
    fp = fopen((char*) ar[255][1], "r"); // открыли файл

    while (!feof(fp)){
        fgets(line, 255, fp);
        if ( strstr(line, (char*) ar[255][2]))
        printf("%s", line);
    }
    fclose(fp);
    return 0;
}