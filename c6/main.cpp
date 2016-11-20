#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main(int argc, char* argv[]) {
	int arg = 4;
	int players = 4;

	struct options {
		int size;
		int life;
		int sleep;
	} op;

	op.size = arg;
	op.life = 10;
	op.sleep = 100;


	srand ( time(NULL) );


    FILE *fp;
    fp = fopen("map", "w");
    	for (int i = 0; i < arg; i++){
	    	for (int j = 0; j < arg; j++)
	    		fprintf(fp, "%3d ", rand()%19-9);
    		fprintf(fp, "\n");
    	}

    	// for (int i = 0; i <= players; i++)
		   //  fprintf(fp, "[%d, %d]        ", rand()%arg, rand()%arg);

    fclose(fp);
	return 0;
}