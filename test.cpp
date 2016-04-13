#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <data/metadata_extension.h>
#include <data/filters.h>
#include "NetSim.h"

using namespace std;

int classCount[]={78, 68, 72, 76, 47, 43, 67, 49};
String directory("2D/CL2D/run_001/");
String fileNames[]={
	"class01.stk",
	"class02.stk",
	"class03.stk",
	"class04.stk",
	"class05.stk",
	"class06.stk",
	"class07.stk",
	"class08.stk"
};

void getPos(int num, int &blockOut, int &posOut);
void getImage(Image<double> &imageOut, int num);

int main(int argc, char **argv)
{
	chdir("/home/yinshuo/XMIPP_exp/2DAnalysis");

	MultidimArray<double> sim(500,500), dis(500,500), cor(500,500);
	for(int i=0; i<500; i++){
		Image<double> img1;
		getImage(img1, i);
		for(int j=0; j<500; j++){
			if(i==j){
				dAij(sim,i,j)=1;dAij(dis,i,j)=0;dAij(cor,i,j)=1;
				continue;
			}
			if(j<i){
				dAij(sim,i,j)=dAij(sim,j,i);dAij(dis,i,j)=dAij(dis,j,i);dAij(cor,i,j)=dAij(cor,j,i);
				continue;
			}
			Image<double>img2;
			getImage(img2, j);
			MultidimArray<double> data1=img1.data, data2=img2.data;
			dAij(sim,i,j)=correlation(data1, data2);
			dAij(dis,i,j)=euclidianDistance(data1, data2);
			dAij(cor,i,j)=correntropy(data1, data2, 0.9);
		}
	}

	Image<double> out(sim);
	String prefix(argv[0]);
	prefix+="_";

	out.write(prefix+"correlation.stk");cout<<"done correlation"<<endl;

	MultidimArray<double> adjacent(500,500);
	CreateAdjacentMatrix(sim, adjacent, 50, Cmp(false));
	out=adjacent; out.write(prefix+"adjacent.stk"); cout<<"done adjacent"<<endl;

	MultidimArray<double> snn(500,500);
	SNN(sim, snn, 50, Cmp(false));
	out=snn; out.write(prefix+"snn.stk");cout<<"done snn"<<endl;

	MultidimArray<double> jaccard(500,500);
	JaccardIndex(sim, jaccard, 50, Cmp(false));
	out=jaccard; out.write(prefix+"jaccard.stk"); cout<<"done jaccard"<<endl;

	MultidimArray<double> sorensen(500,500);
	SorensenIndex(sim, sorensen, 50, Cmp(false));
	out=sorensen; out.write(prefix+"sorensen.stk"); cout<<"done sorensen"<<endl;

	MultidimArray<double> hd(500,500);
	HDIndex(sim, hd, 50, Cmp(false));
	out=hd; out.write(prefix+"hd.stk"); cout<<"done hd"<<endl;

	MultidimArray<double> ra(500,500);
	RAIndex(sim, ra, 50, Cmp(false));
	out=ra; out.write(prefix+"ra.stk"); cout<<"done ra"<<endl;

	MultidimArray<double> lp(500,500);
	LPIndex(sim, lp, 50, Cmp(false),0.3);
	out=lp; out.write(prefix+"lp.stk"); cout<<"done lp"<<endl;

	MultidimArray<double> katz(500,500);
	KatzIndex(sim, katz, 50, Cmp(false),0.01);
	out=katz; out.write(prefix+"katz.stk"); cout<<"done katz"<<endl;

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
	string fileName = directory+fileNames[block];

	FileName name;
	name.compose(pos+1, fileName);

	imageOut.read(name);
	//cout<<imageName<<endl;
}