#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define SIZE 2352
#define  CLASS 6
#define PI 3.1415926
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
using namespace std;
int main()
{
	FILE *fp_in, *fp_train, *fp_test, *fp_exam;
	fp_train = fopen("all_train.txt", "w+");
	fp_test = fopen("all_test.txt", "w+");
	//fp_exam = fopen("all_exam.txt","w+");

	srand(time(NULL));
	int i = 0, j, index;
	double azimuth, elevation;
	
	for (i = 1; i <= CLASS; i++){
		int aCache[SIZE], eCache[SIZE], num[SIZE];
		char file_info[30] = "viewpoints_";
		char *post = ".txt", str[3];
		_itoa(i, str, 10);
		strcat(file_info, &str[0]);
		strcat(file_info, post);
		fp_in = freopen(file_info, "r", stdin);
		while (scanf("%d%lf%lf", &index, &azimuth, &elevation) != EOF)
		{
			num[index] = index;
			aCache[index] = (int)(azimuth * 180 / PI);
			eCache[index] = (int)(elevation * 180 / PI);
		}
		
		for (int k = 0; k < 360; k+=15)
			for (int j = 0; j < SIZE; j++){
				int rnd = rand() % (SIZE - j);
				if (j < 2156)
					//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
					fprintf(fp_train, "/media/cad/Elements1/viewpoint/fish-white/rr%d-%d/%d.bmp %d\n", k, i, num[rnd], num[rnd]);
					//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n",  i, num[rnd], num[rnd]);
				else //if (j<1960)
					//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
					fprintf(fp_test, "/media/cad/Elements1/viewpoint/fish-white/rr%d-%d/%d.bmp %d\n", k, i, num[rnd], num[rnd]);
					//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n", i, num[rnd], num[rnd]);
				//else 
					//fprintf(fp_exam, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp %d\n", i, k, i, num[rnd], num[rnd]);
				SWAP(aCache[rnd], aCache[SIZE - j - 1], int);
				SWAP(eCache[rnd], eCache[SIZE - j - 1], int);
				SWAP(num[rnd], num[SIZE - j - 1], int);
			}

		for (int k = 0; k < 360; k += 15)
			for (int j = 0; j < SIZE; j++){
			int rnd = rand() % (SIZE - j);
			if (j < 2156)
				//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
				fprintf(fp_train, "/media/cad/Elements1/viewpoint/fish-black/rr%d-%d/%d.bmp %d\n", k, i, num[rnd], num[rnd]);
			//fprintf(fp_train, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n",  i, num[rnd], num[rnd]);
			else //if (j<1960)
				//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp 0 %d %d\n",i, k, i, num[rnd], aCache[rnd], eCache[rnd]);
				fprintf(fp_test, "/media/cad/Elements1/viewpoint/fish-black/rr%d-%d/%d.bmp %d\n", k, i, num[rnd], num[rnd]);
			//fprintf(fp_test, "/home/cad/disk/linux/RenderForCNN-master/data/engine/small-%d/%d.bmp %d\n", i, num[rnd], num[rnd]);
			//else 
			//fprintf(fp_exam, "/home/cad/disk/linux/RenderForCNN-master/data/engine/r%d/rr%d-small-%d/%d.bmp %d\n", i, k, i, num[rnd], num[rnd]);
			SWAP(aCache[rnd], aCache[SIZE - j - 1], int);
			SWAP(eCache[rnd], eCache[SIZE - j - 1], int);
			SWAP(num[rnd], num[SIZE - j - 1], int);
			}

	}
}