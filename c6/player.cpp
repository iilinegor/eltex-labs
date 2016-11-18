#include <stdio.h>
#include <stdlib.h>
#include <ctime>

struct options {
		int size;
		int life;
		int sleep;
	};


int main(int argc, char* argv[]) {
	
	srand ( time(NULL) );

	int map[255];
	int x = rand()%16,
		y = rand()%16,
		size = 18,
		life = 19,
		sleep = 100,
		dir = 0;

// 0 - up
// 1 - down
// 2 - left
// 3 - right

	int dirx = size / 2 - x;
	int diry = size / 2 - y;

	dir = (abs(dirx) > abs(diry)) ? ((dirx >= 0) ? 2 : 3) : ((diry >= 0) ? 0 : 1);

	printf("[%d, %d]: direction %d\n", x, y, dir);

	FILE *fp;
	fp = fopen("map", "r");
			for (int i = 0; i < size*size; i++){
		        fscanf(fp, "%d", map+i);
		        printf("%d\n", map[i]);
		    }
    fclose(fp);

    switch (dir) {
    	case 0:
    		if (y < size) 
    			// gameover! 
    			return life;
    		else {

    		}
    		break;

    	case 1:
    		if (y > (size - 2) * (size - 1)) 
    			// gameover! 
    			return life;
    		else {

    		}
    		break;

    	case 2:
    		if (x = 0) 
    			// gameover! 
    			return life;
    		else {

    		}
    		break;

    	case 3:
    		if (x = (size - 1) * (size - 1)) 
    			// gameover! 
    			return life;
    		else {

    		}
    		break;

    }


	return 0;
}
