#include <iostream>
using namespace std;
int main(){
	int xiSize = 256, yiSize = 256, ziSize = 106;
	FILE *fp = fopen("E:\\ZJU\\VIEWPOINT\\MyData\\Head\\CT_256x256x106\\CT_256x256x106.raw", "rb");
	if (fp == NULL) {
		cout << "Can't open data file " << endl;
		return false;
	}
	FILE *fp_out = fopen("E:\\ZJU\\VIEWPOINT\\MyData\\Head\\CT_256x256x106\\CT_256x256x106r.raw", "wb");
	unsigned char* pOriginalData;
	unsigned char* pChangedData;
	pOriginalData = new unsigned char[xiSize * yiSize * ziSize];
	pChangedData  = new unsigned char[xiSize * yiSize * ziSize];
	fread(pOriginalData, sizeof(unsigned char), xiSize * yiSize * ziSize, fp);
	for (int z = 0; z < ziSize; ++z)
		for (int y = 0; y < yiSize; ++y)
			for (int x = 0; x < xiSize; ++x) {
		int index = z * xiSize * yiSize + y * xiSize + x;
		//int indexNew = i * xiSize * yiSize + j * xiSize + k;
		int indexNew = (ziSize-1-z)*xiSize *yiSize + y*xiSize + x;
		pChangedData[indexNew] = pOriginalData[index];
			}
	fwrite(pChangedData, sizeof(unsigned char), xiSize * yiSize * ziSize, fp_out);
}

