#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define  COUNT 250
#define PI 3.1415926
#define NEAR 12
double dist(double phia, double thetaa, double phib, double thetab){
	phia = phia - PI / 2;
	phib = phib - PI / 2;
	return acos(cos(phia)*cos(phib)*cos(thetab - thetaa) + sin(phia)*sin(phib));
}

int main(){
	FILE *fp = NULL;
	fp = fopen("angle_class.txt", "r");
	float azimuth[2352], elevation[2352];
	int idx;
	for (int i = 0; i < 2352; i++){
		fscanf(fp, "%d%f%f", &idx, &elevation[i], &azimuth[i]);
	}
	
	int truth[COUNT], pri ,tmp;
	idx = 0;
	freopen("tooth_label.txt", "r", stdin);
	freopen("tooth1_dis.txt", "w", stdout);
	while (scanf("%d", &tmp) != EOF){
		truth[idx++] = tmp;
	}

	int acc[15] = { 0 };
	freopen("tooth1.txt", "r", stdin);
	
	for (int i = 0; i < NEAR; i++){
		for (int k = 0; k < COUNT; k++){
			scanf("%d", &pri);
			double sphere_dis = dist(elevation[pri] / 180 * PI, azimuth[pri] / 180 * PI, elevation[truth[k]] / 180 * PI, azimuth[truth[k]] / 180 * PI) * 180 / PI;
			printf("%d %d %f\n", pri, truth[k], sphere_dis);
			for (int j = 14; j >= 0; j--)
			{
				double bound = acos((float)(1 - (2 * j*(j + 1) + 1) / 1176.0)) * 180 / PI;
				if (sphere_dis < bound)
					acc[j]++;
				else
					break;
			}
		}
	}

	for (int i = 0; i < 15; i++){
		printf("acc%d %d\n", i, acc[i]);
	}
}
