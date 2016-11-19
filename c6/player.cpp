#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int map[255];

struct options {
		int size;
		int life;
		int sleep;
	};

void setMap(int size) {
	FILE *fp;
	fp = fopen("map", "w");
			for (int i = 0; i < size; i++){
		        // fscanf(fp, "%d", map+i);
		        for (int j = 0; j < size; j++) {
			        fprintf(fp, "%d ", map[j*size +i]);
			        printf("%3d", map[j*size +i]);
		    	}
		    	fprintf(fp, "\n");
		    	printf("\n");
		    }
    fclose(fp);
}


int main(int argc, char* argv[]) {
	
	srand ( time(NULL) );

	
	int size = 4,
		x = rand()%size,
		y = rand()%size,
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
		        // printf("%d\n", map[i]);
		    }
    fclose(fp);

    switch (dir) {
    	case 0:
    		if (y < size) 
    			// gameover! 
    			{printf("done!");
    			    			return life;}
    		else {
    			map[ y*size + x ] = 0;
    			life += map[ (y - 1) * size + x ];
    			map[ (y - 1) * size + x ] = -1 * life;
    		}
    		break;

    	case 1:
    		if (y >= (size - 2) * (size - 1)) 
    			// gameover! 
    			{printf("done!");
    			    			return life;}
    		else {
    			map[ y*size + x ] = 0;
    			life += map[ (y + 1) * size + x ];
    			map[ (y + 1) * size + x ] = -1 * life;
    		}
    		break;

    	case 2:
    		if (x = 0) 
    			// gameover! 
    			{printf("done!");
    			    			return life;}
    		else {
    			map[ y*size + x ] = 0;
    			life += map[ y*size + x - 1 ];
				map[ y*size + x - 1 ] = -1 * life;    			

    		}
    		break;

    	case 3:
    		if (x = (size - 1) * (size - 1)) 
    			// gameover! 
    			{printf("done!");
    			    			return life;}
    		else {
    			map[ y*size + x ] = 0;
    			life += map[ y*size + x + 1 ];
				map[ y*size + x + 1 ] = -1 * life;
    		}
    		break;
    }

    setMap(size);

    if ( life <= 0 )
    	printf("Bang-bang you'r dead");


	return 0;
}
