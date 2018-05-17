#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define SIZE 2352
#define  AMOUNT 2352
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
	//fp_exam = fopen("all_exam.txt","w+");
	int sample_count[SIZE], idx, num[AMOUNT];
	float prob;
	
	srand(time(NULL));
	int i = 0, j, index;
	double azimuth, elevation;
	//char* subclass[3] = { "head", "vismale", "mri" };
	char* subclass[3] = { "tree1", "tree2", "tree3" };
	int numSub[3] = { 2, 3, 6 };
	char* order[4] = { "white", "black", "persWhite", "persBlack" };
	for (int i = 0; i < SIZE; i++){
		num[i] = i;
	}

	for (int a = 0; a < 3;a++)
	for (int b = 0; b < 2; b++)
		for (i = 1; i <= numSub[a]; i++){
			for (int k = 0; k < 360; k+=STEP)
				for (int j = 0; j < AMOUNT; j++){
					int rnd = rand() % (AMOUNT - j);
					if (j < AMOUNT - 196)					//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
						fprintf(fp_train, "/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/tree/%s/%s/r%d/rr%d-%d/%d.bmp %d\n",subclass[a], order[b], i, k, i, num[rnd], num[rnd]);
						//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n",  i, num[rnd], num[rnd]);
					else //if (j<1960)
						//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
						fprintf(fp_test, "/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/tree/%s/%s/r%d/rr%d-%d/%d.bmp %d\n", subclass[a], order[b], i, k, i, num[rnd], num[rnd]);
						//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n", i, num[rnd], num[rnd]);
					//else 
						//fprintf(fp_exam, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp %d\n", i, k, i, num[rnd], num[rnd]);
					SWAP(num[rnd], num[AMOUNT - j - 1], int);
				}
		}
}