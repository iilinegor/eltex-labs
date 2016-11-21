#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	int arg = argv[1] ? atoi(argv[1]) : 4;
	int players = 4;

	struct options {
		int size;
		int life;
		int sleep;
	} op;

	op.size = arg;
	op.life = 10;
	op.sleep = 100;


	srand ( getpid() );


    FILE *fp;
			fp = fopen("map", "w");
			for (int i = 0; i < arg; i++){
				for (int j = 0; j < arg; j++)
					fprintf(fp, "%3d ", rand()%19-9);
				fprintf(fp, "\n");
			}
			fclose(fp);


	// pid_t pid[10];
	// int i;
	// pid[0] = fork();
	
			printf("%d\n", getpid());


	pid_t pid[10];
	// int c;
	// pid[c] = fork();
	for (int c = 0; c < 10; c++) {
		;
		if (!(pid[c] = fork())){
				printf("-ДОЧЕРНИЙ-\n");
				// printf("%d\n", (int) );
				char str[5] = "";
				sprintf(str, "%d", arg);
				execl("./player","player", str, NULL);
				// return(0);
		}
		else {
			printf("+РОДИТЕЛЬСКИЙ+\n");
			for (int c = 0; c < 10; c++)
				waitpid (pid[c], NULL, 0);
			
		}
	}

	

			


	
	// for (i = 0; i  < 10; i++){
	// 	pid[i] = fork();
	// 	if (pid[i] == 0){
	// 		printf("-ДОЧЕРНИЙ-\n");
	// 		if (execl("./player","player",arg, NULL)<0) {
	// 			printf("ERROR while start processing file %s\n",argv[i]);
	// 			exit(-2);
	// 		}
	// 		else printf( "processing started (pid=%d)\n",pid[i]);
	// 	}
	// 	return(0);
	// }
	return 0;
}