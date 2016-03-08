#include <iostream>
#include <string>
#include <data/xmipp_image.h>
#include <data/metadata_extension.h>
#include <data/filters.h>

using namespace std;

String blockNames[]={
		"class000001_images",
		"class000002_images",
		"class000003_images",
		"class000004_images",
		"class000005_images",
		"class000006_images",
		"class000007_images",
		"class000008_images"
};
int classCount[]={78, 68, 72, 76, 47, 43, 67, 49};
FileName fn("/home/yinshuo/XMIPP_exp/2DAnalysis/2D/CL2D/run_001/extra/level_02/level_classes.xmd");

void getPos(int num, int &blockOut, int &posOut);
void getImage(Image<double> &imageOut, int num);

int main()
{
	chdir("/home/yinshuo/XMIPP_exp/2DAnalysis");

	MultidimArray<double> sim(500,500);
	for(int i=0; i<500; i++){
		cout<<i<<" ";
		Image<double> img1;
		getImage(img1, i);
		for(int j=0; j<500; j++){
			if(i==j){
				dAij(sim,i,j)=1;
				continue;
			}
			if(j<i){
				dAij(sim, i, j) = dAij(sim, j, i);
				continue;
			}
			Image<double>img2;
			getImage(img2, j);
			MultidimArray<double> data1=img1.data, data2=img2.data;
			dAij(sim,i,j)=correlation(data1, data2);
		}
	}

	Image<double> out(sim);
	out.write("correlation.stk");

	return 0;
}

void getPos(int num, int &blockOut, int &posOut)
{
	blockOut=0;
	posOut=0;
	while(classCount[blockOut]<=num){
		num-=classCount[blockOut];
		blockOut++;
	}
	posOut=num;
}

void getImage(Image<double> &imageOut, int num)
{
	int block, pos;
	getPos(num, block, pos);
	string blockName = blockNames[block];

	MetaData md;
	FileName name;
	name.compose(blockName, fn);
	md.read(name);

	String imageName;
	md.getValue(MDL_IMAGE, imageName, pos+1);

	imageOut.read(imageName);
	//cout<<imageName<<endl;
}
