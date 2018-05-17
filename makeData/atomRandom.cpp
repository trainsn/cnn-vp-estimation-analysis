#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define SIZE 540
#define  AMOUNT 540
#define  CLASS 7
#define STEP 15
#define PI 3.1415926
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
using namespace std;
int main()
{
	FILE *fp_in, *fp_train, *fp_test, *fp_exam;
	
	fp_train = fopen("all_train.txt", "w+");
	fp_test = fopen("all_test.txt", "w+");

	int sample_count[SIZE], idx, num[AMOUNT];
	float prob;
	
	srand(time(NULL));
	int i = 0, j, index;
	double azimuth, elevation;
	char* order[4] = { "white", "black", "persWhite", "persBlack" };
	bool valid[SIZE] = { 0 };

	//system("pause");

	for (int i = 0; i < SIZE; i++){
		num[i] = i;
	}

	for (int b = 0; b < 4; b++)
		for (i = 1; i <= CLASS; i++){
				for (int j = 0; j < AMOUNT; j++){
					int rnd = rand() % (AMOUNT - j);
						if (j < AMOUNT -60){
							fprintf(fp_train, "/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/atom/%s/%d/%d_%d.bmp %d\n", order[b], i, num[rnd]/3,num[rnd]%3, num[rnd]/3);
						}
						//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n",  i, num[rnd], num[rnd]);
						else //if (j<1960)
							//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
							fprintf(fp_test, "/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/atom/%s/%d/%d_%d.bmp %d\n", order[b], i, num[rnd] / 3, num[rnd] % 3, num[rnd] / 3);
					SWAP(num[rnd], num[AMOUNT - j - 1], int);
				}
		}
}