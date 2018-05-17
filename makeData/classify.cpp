#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define CLASS 12
#define SIZE 300
#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
int main(void){
	char* class_train[CLASS] = { "atom", "engine", "fish", "foot", "head", "head-mri", "tooth", "tree1", "tree2", "tree3", "vessel", "vismale" };
	char* class_test[8] = { "atom", "engine", "fish", "foot", "head", "tooth", "tree", "vessel" };
	int num_all[CLASS] = { 8, 12, 7, 6, 10, 2, 5, 2, 3, 4, 5, 4 };
	int num_train[CLASS] = { 6, 7, 4, 4, 7, 1, 4, 2,  3, 2, 3, 3 };
	int train_tf[12][10] = {
			{ 1, 2, 4, 5, 6, 8 },
			{ 1, 2, 3, 5, 6, 8, 9 },
			{1,3,4,6},
			{1,2,3,5},
			{1,2,3,5,6,7,8},
			{1},
			{1,2,3,4},
			{1,2},
			{1,2,3},
			{1,2},
			{1,2,5},
			{1,2,3}
	};
	bool train_test[12][13] = { 0 };
	for (int i = 0; i < CLASS; i++){
		for (int j = 0; j < num_train[i]; j++)
			train_test[i][train_tf[i][j]] = 1;
	}
	int res[12] = { 0, 1, 2, 3, 4, 4, 5, 6, 6, 6, 7, 4};
	char* color[2] = { "white", "black" };
	FILE  *fp_train, *fp_test;
	int num[SIZE];
	fp_train = fopen("classify_train.txt", "w+");
	fp_test = fopen("classify_test.txt", "w+");

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
		num[i] = i;
	for (int i = 0; i < 12; i++){
		for (int j = 1; j <= num_all[i]; j++)
			{
			for (int k = 0; k < 360; k += 45)
				for (int co = 0; co < 2; co++){
				for (int l = 0; l < 45; l++)
				{
					int rnd = rand() % (SIZE - l);
					if (train_test[i][j])
						fprintf(fp_train, "/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/classify/%s/%s/r%d/rr%d-%d/%d.bmp %d\n", class_train[i], color[co], j, k, j, rnd, res[i]);
					else 
						fprintf(fp_test, "/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/classify/%s/%s/r%d/rr%d-%d/%d.bmp %d\n", class_train[i], color[co], j, k, j, rnd, res[i]);
					SWAP(num[rnd], num[SIZE - l - 1], int);
				}
				}
			}				
		}
}