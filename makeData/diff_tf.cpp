#include <stdio.h>
#define CLASS 1
#define NUM 5
#define COUNT 2352
int main(){
	freopen("all_test.txt", "w", stdout);
	for (int i = 0; i < CLASS; i++)
		for (int j = 0; j < NUM; j++)
			for (int k = 0; k < COUNT; k++)
				printf("/media/cad/3fafa74e-c460-4512-8fb2-4a08ea3c1ef7/fish/test/tf%d/%d/%d.bmp %d\n", i+1, j+1, k, k);
}