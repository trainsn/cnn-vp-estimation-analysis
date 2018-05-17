#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926
#define NUM 36000
double dist(double phia, double thetaa, double phib, double thetab ){
	phia = phia - PI / 2;
	phib = phib - PI / 2;
	return acos(cos(phia)*cos(phib)*cos(thetab - thetaa) + sin(phia)*sin(phib));
}

int main()
{
	freopen("output_head_test.log", "r", stdin);
	freopen("acc_head_angle.txt", "w", stdout);
	int cls,idx;
	float truth_theta[NUM], pri_theta[NUM], truth_phi[NUM], pri_phi[NUM];
	int i_theta=0, i_phi=0;
	for (int i = 0; i < NUM*2; i++)
	{
		scanf("%d%d", &cls, &idx);
		if (!cls){
			scanf("%f%f", &truth_theta[i_theta], &pri_theta[i_theta]);
			truth_theta[i_theta] = (truth_theta[i_theta] + 0.5) /180*PI;
			pri_theta[i_theta] = (pri_theta[i_theta] + 0.5) / 180 * PI;
			i_theta++;
		}
		else{
			scanf("%f%f", &truth_phi[i_phi], &pri_phi[i_phi]);
			truth_phi[i_phi] = (truth_phi[i_phi] + 0.5) / 180 * PI;
			pri_phi[i_phi] = (pri_phi[i_phi] + 0.5) / 180 * PI;
			i_phi++;
		}
	}

	int acc[15] = { 0 };
	for (int i = 0; i < NUM; i++){
		double sphere_dis = dist(truth_phi[i], truth_theta[i], pri_phi[i], pri_theta[i]);
		for (int j = 14; j >= 0; j--)
		{
			double bound = acos((float)(1 - (2 * j*(j + 1) + 1) / 1176.0)) * 180 / PI;
			if (sphere_dis * 180 / PI < bound)
				acc[j]++;
			else 
				break;
		}
	
	}	
	for (int i = 0; i < 15; i++){
		printf("acc%d %lf\n", i, (double)acc[i]/NUM);
	}
}