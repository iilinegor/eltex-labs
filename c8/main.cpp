#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <mqueue.h>

#define MY_MQ_NAME "/my_mq"

static struct mq_attr my_mq_attr;
static mqd_t my_mq;


struct child {
	int pid;
	int score;
	int pipe[2];
};

int player(int);

int campdet(const void *a, const void *b) {
    child aa = *((child*) a);
    child bb = *((child*) b);
    return bb.score/256 - aa.score/256;
};


int main(int argc, char* argv[]) {
	char buf[6];
	int arg = argv[1] ? atoi(argv[1]) : 4;

	srand ( getpid() );

    FILE *fp;
			fp = fopen("map", "w");
			for (int i = 0; i < arg; i++){
				for (int j = 0; j < arg; j++)
					fprintf(fp, "%3d ", rand() % 19 - 9);
				fprintf(fp, "\n");
			}
			fclose(fp);


	my_mq_attr.mq_maxmsg = 10;
    my_mq_attr.mq_msgsize = sizeof(buf);

    my_mq = mq_open(MY_MQ_NAME, \
                    O_CREAT | O_RDWR | O_NONBLOCK, \
                    0777, \
                    &my_mq_attr);

	child list[10];


	for (int c = 0; c < 10; c++) {
		// pipe(list[c].pipe);
		// printf("%d %d\n",  list[c].pipe[0], list[c].pipe[1]);

		if (!(list[c].pid = fork())){
				char str[5] = "";
				char str1[5] = "";
				sprintf(str, "%d", 2);
				sprintf(str1, "%d", my_mq);
				// player(4);
				execl("./player","player", str, str1, NULL);

		}
		else {
			for (int c = 0; c < 10; c++){
				waitpid (list[c].pid, &(list[c].score), 0);	

				// read(list[c].pipe[0], buf, 3);
				// printf(">%d %s", list[c].pid, buf);
			}
		}
	}

	qsort(list, 10, sizeof(list[0]), campdet);

	for (int c = 0; c < 10; c++) {	
			mq_receive(my_mq, buf, sizeof(buf), NULL);
			printf(">%5d %d\t\n", list[c].pid, list[c].score/256);	
		}

	return 0;
}


