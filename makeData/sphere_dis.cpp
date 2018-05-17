#include<stdio.h>
#include<math.h>
#define CLASS 2352
float dist(double thetaa, double phia, double thetab, double phib){
	return acos(cos(thetaa)*cos(thetab)*cos(phib - phia) + sin(thetaa)*sin(thetab));
}
void main(void)
{
	freopen("e:\\engine\\angle_class.txt", "r", stdin);
	int cls;	
	double theta[CLASS], phi[CLASS];
	double dis[10*CLASS],temp;
	printf("ok");
	for (int i = 0; i < CLASS; i++){
		scanf("%d%lf%lf", &cls, &theta[i], &phi[i]);
	}
	for (int i = 0; i < CLASS;i++)
		for (int j = i+1; j < CLASS; j++){
		temp = dist(theta[i], phi[i], theta[j], phi[j]);		
		}
}