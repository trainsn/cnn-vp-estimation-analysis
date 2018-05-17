#include <iostream>
#include <stdio.h>
#include <string>
#define SIZE 98
#define  STEP 15
using namespace std;
int main(){
	float x, y;
	int idx;
	char file_idx[100];
	char* order[4] = { "white", "black", "persWhite", "persBlack" };
	freopen("cla_idx_head.txt", "r", stdin);
	freopen("file_list_vismale2.txt", "w", stdout);
	while (scanf("%s",file_idx)!=EOF){
		printf("%s 0\n",file_idx); 
		scanf("%d%f%f", &idx, &x, &y);
		for (int b = 0; b < 2; b++)
			 for (int k = 0; k < 360; k += STEP)
			 	printf("/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/head/vismale-gray/%s/r%d/rr%d-%d/%d.bmp %d\n", order[b], 2, k, 2, idx, 4);
			//printf("/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/atom-gray/%s/%d_1.bmp 0\n", order[b], idx);
	}
}