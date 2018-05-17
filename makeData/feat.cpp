#include <stdio.h>
#include <math.h>
#include <vector>
#include <assert.h>
using namespace std;
#define CLASS 12
#define SIZE 4096 
float getMold(const vector<float>& vec){   //求向量的模长  
	int n = vec.size();
	float sum = 0.0;
	for (int i = 0; i < n; ++i)
		sum += vec[i] * vec[i];
	return sqrt(sum);}

//求两个向量的余弦相似度  
float getSimilarity(const vector<float>& lhs, const vector<float>& rhs){
	int n = lhs.size();
	assert(n == rhs.size());
	float tmp = 0.0;  //内积  
	for (int i = 0; i < n; ++i)
		tmp += lhs[i] * rhs[i];
	return tmp / (getMold(lhs)*getMold(rhs));
}

int main(){
	freopen("feat_vector.txt", "r", stdin);
	freopen("feat_simi.txt", "w", stdout);
	vector<vector <float>> feat;
	feat.resize(CLASS, vector<float>(SIZE));

	//float feat[CLASS][SIZE];
	float mold[CLASS] = {0};
	float cosres[CLASS][CLASS] = { 0 };
	for (int i = 0; i < CLASS; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			scanf("%f", &feat[i][j]);
			//mold[i] += feat[i][j] * feat[i][j];
		}
		//mold[i] = sqrt(mold[i]);
		mold[i] = getMold(feat[i]);
	}

	for (int i = 0; i < CLASS; i++){
		for (int j = i + 1; j < CLASS; j++){
// 			for (int k = 0; k < SIZE; k++){
// 				cosres[i][j] += feat[i][k] * feat[j][k];
// 			}
// 			cosres[i][j] /= mold[i] * mold[j];
			cosres[i][j] = getSimilarity(feat[i], feat[j]);
			printf("%d %d %f\n", i+1, j+1, cosres[i][j]);
		}
	}		
}