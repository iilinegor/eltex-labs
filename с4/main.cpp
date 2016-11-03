#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]) {
    int i = 0;
    char line[255];
    FILE *fp;

    fp = fopen(argv[1], "r");
    while (!feof(fp)){
        fgets(line, 255, fp);
        if ( strstr(line, (char*) argv[2]))
            printf("%s", line);
    }
    printf("\n");
    fclose(fp);
    return 0;
}