#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	for (int i = 0; i < 15; i++){
		printf("%d %f\n", i, acos((float)(1 - (2 * i*(i + 1) + 1) / 1176.0))*180/3.1415926);
	}
	system("pause");
}