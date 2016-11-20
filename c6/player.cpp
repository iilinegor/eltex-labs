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

	int size = 4,
		x = rand()%size,
		y = rand()%size,
		life = size,
		sleep = 100,
		dir = 0;

	int map[size][size];

// 0 - up
// 1 - down
// 2 - left
// 3 - right

	int dirx = size / 2 - x;
	int diry = size / 2 - y;

	dir = (abs(dirx) > abs(diry)) ? ((dirx >= 0) ? 3 : 2) : ((diry >= 0) ? 1 : 0);



	printf("[%d, %d]: direction %d\n\n", x, y, dir);

	for (int l = 0; l < 4; l++ ) {
		FILE *fp;
		fp = fopen("map", "r");
				for (int i = 0; i < size; i++){
			        for (int j = 0; j < size; j++) {
				        fscanf(fp, "%d", &(map[j][i]));
			    	}
			    }
	    fclose(fp);
	    

	    switch (dir) {
	    	case 0:
	    		if (y == 0){
	    			printf("done!\n");
	    			return life;
	    		}
	    		else {
	    			map[x][y] = 0;
	    			life += map[x][y-1];
	    			map[x][y-1] = (-1) * life;
	    			y -= 1;
	    		}
	    		break;

	    	case 1:
	    		if (y == size - 1){
	    			printf("done!\n");
	    			return life;
	    		}
	    		else {
	    			map[x][y] = 0;
	    			life += map[x][y+1];
	    			map[x][y+1] = (-1) * life;
	    			y += 1;
	    		}
	    		break;

	    	case 2:
	    		if (x == 0){
	    			printf("done!\n");
	    			return life;
	    		}
	    		else {
	    			map[x][y] = 0;
	    			life += map[x-1][y];
	    			map[x-1][y] = (-1) * life;
	    			x -= 1;
	    		}
	    		break;

	    	case 3:
	    		if (x == (size - 1)){
	    			printf("done!\n");
	    			return life;
	    		}
	    		else {
	    			map[x][y] = 0;
	    			life += map[x+1][y];
	    			map[x+1][y] = (-1) * life;
	    			x += 1;
	    		}
	    		break;
	    }

		printf("     VVVV\n\n");


	    fp = fopen("map", "w");
				for (int i = 0; i < size; i++){
			        // fscanf(fp, "%d", map+i);
			        for (int j = 0; j < size; j++) {
				        fprintf(fp, "%d ", map[j][i]);
				        printf("%3d", map[j][i]);
			    	}
			    	fprintf(fp, "\n");
			    	printf("\n");
			    }

	    fclose(fp);

	    printf("\n");

	    if ( life <= 0 ){
	    	printf("\nBang-bang you'r dead\n");
	    	break;
	    }
	}    
	return 0;
}