#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1200
#define  CLASS 10
#define PI 3.1415926
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
int main()
{
	FILE *fp;
	freopen("view_angle.txt", "r", stdin);
	fp = freopen("all_test.txt", "w", stdout);
	srand(time(NULL));
	int i=0,j;
	double azimuth, elevation;
	double aCache[12000], eCache[12000];
	int num[12000],tempv,tempi;

	while (scanf("%lf%lf", &azimuth, &elevation) != EOF)
	{
		aCache[i++] = azimuth;
		eCache[i-1] = elevation;
	}
	for (i = 1; i < CLASS; i++)
		for (j = 0; j < SIZE;j++)
		{
		aCache[i*SIZE + j] = aCache[j];
		eCache[i*SIZE + j] = eCache[j];
		}
	for (i = 0; i < SIZE*CLASS; i++)
	{
		num[i] = i;
	}

	for (i = 0; i < CLASS*SIZE; i++)
	{
		int index = rand() % (CLASS*SIZE-i);
		int value = num[index];
		int type = value/SIZE;
		printf("/home/cadevil/RenderForCNN-master/data/headimages/00000001/%d/%d.bmp ", type, value%SIZE);
		printf("%d %d %d\n", 0, (int)(aCache[index] * 180 / PI), (int)(eCache[index] * 180 / PI));
 
		SWAP(aCache[index], aCache[CLASS*SIZE - i-1], double);
		SWAP(eCache[index], eCache[CLASS*SIZE - i-1], double);
		SWAP(num[index], num[CLASS*SIZE - i-1], int);
		if (i == SIZE * 2 - 1)
		{
			fclose(fp);
			fp = freopen("all_train.txt", "w", stdout);
		}
	}
	fclose(fp);
}