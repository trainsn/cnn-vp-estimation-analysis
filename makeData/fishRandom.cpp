#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define SIZE 2352
#define  AMOUNT 3545
#define  CLASS 6
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
	int sample_count[SIZE], idx, num[AMOUNT], key[AMOUNT], temp = 0;
	
	fp_in = freopen("fishData.txt", "r", stdin);
	char* order[4] = { "white", "black", "persWhite", "persBlack" };
	char file_name[AMOUNT][20];
	
	int i = 0, j, index;
	for (i = 0; i < AMOUNT; i++)
	{
		fscanf(fp_in, "%d%d", &num[i],&key[i]);
	}
		
	
	srand(time(NULL));
	
	for (int b = 0; b < 2;b++)
		for (i = 1; i <= CLASS; i++){
			for (int k = 0; k <= 345; k+=STEP)
				//if (fabs((float)k - 90) <= 15 || fabs((float)k-270)<=15 )
				for (int j = 0; j < AMOUNT; j++){
					int rnd = rand() % (AMOUNT - j);
					if (j < AMOUNT - 196)
						//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
						fprintf(fp_train, "/media/cad/Elements/viewpoint/fish/%s/r%d/rr%d-%d/%d_%d.bmp %d\n",order[b],i, k, i, num[rnd],key[rnd], num[rnd]);
						//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n",  i, num[rnd], num[rnd]);
					else //if (j<1960)
						//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
						fprintf(fp_test, "/media/cad/Elements/viewpoint/fish/%s/r%d/rr%d-%d/%d_%d.bmp %d\n", order[b], i, k, i, num[rnd], key[rnd], num[rnd]);
						//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n", i, num[rnd], num[rnd]);
					//else 
						//fprintf(fp_exam, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp %d\n", i, k, i, num[rnd], num[rnd]);
					SWAP(num[rnd], num[AMOUNT - j - 1], int);
					SWAP(key[rnd], key[AMOUNT - j - 1], int);
				}
		}
}