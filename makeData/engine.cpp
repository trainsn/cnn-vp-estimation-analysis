#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define SIZE 1200
#define  CLASS 10
#define PI 3.1415926
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
using namespace std;
int main()
{
	FILE *fp;
	srand(time(NULL));
	int i = 0, j, index;
	double azimuth, elevation;
	freopen("all.txt", "w", stdout);
	for (i = 0; i < 9; i++){
		char file_info[30] = "viewpoints_";
		char *post = ".txt", num[2];
		_itoa(i, num, 10);
		strcat(file_info, &num[0]);
		strcat(file_info, post);
		fp = freopen(file_info, "r", stdin);
		while (scanf("%d%lf%lf",&index, &azimuth, &elevation) != EOF)
		{
			int conv_azimuth = (int)(azimuth * 180 / PI);
			int conv_elevation = (int)(elevation * 180 / PI);
			printf("/home/cad/disk/linux/RenderForCNN-master/data/engine/%d/%d.bmp 0 %d %d\n", i, index, conv_azimuth, conv_elevation);
		}				fclose(fp);
	}
}