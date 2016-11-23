#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

struct child {
	int pid;
	int score;
};

int campdet(const void *a, const void *b) {
    child aa = *((child*) a);
    child bb = *((child*) b);
    return bb.score/256 - aa.score/256;
};


int main(int argc, char* argv[]) {
	int arg = argv[1] ? atoi(argv[1]) : 4;

	srand ( getpid() );

    FILE *fp;
			fp = fopen("map", "w");
			for (int i = 0; i < arg; i++){
				for (int j = 0; j < arg; j++)
					fprintf(fp, "%3d ", rand()%19-9);
				fprintf(fp, "\n");
			}
			fclose(fp);

	child list[10];
	for (int c = 0; c < 10; c++) {
		if (!(list[c].pid = fork())){
				char str[5] = "";
				sprintf(str, "%d", arg);
				execl("./player","player", str, NULL);
		}
		else {
			for (int c = 0; c < 10; c++)
				waitpid (list[c].pid, &(list[c].score), 0);	
		}
	}

	qsort(list, 10, sizeof(list[0]), campdet);

	for (int c = 0; c < 10; c++) {
			printf("%d : %d\n", list[c].pid, list[c].score/256);			
		}

	return 0;
}