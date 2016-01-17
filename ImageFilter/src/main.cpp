#include <iostream>
#include <data/xmipp_image.h>
#include <data/filters.h>

using namespace std;

void printInfo(ImageInfo &info);
void MultidimArrayTest();

int main(int argc, char**argv)
{
	if(argc!=2){
		cout<<"Need an Input Image"<<endl;
		return -1;
	}
	Image<double> img;
	try{
		img.read(argv[1],HEADER);
	}
	catch(XmippError){
		cout<<"Can't open file!"<<endl;
		return -1;
	}

	ImageInfo info;
	img.getInfo(info);
	printInfo(info);
	MultidimArrayTest();

	return 0;
}

void printInfo(ImageInfo &info)
{
	cout<<"DataType is: "<<datatype2Str(info.datatype)<<endl;
	cout<<"Dimensions is: "<<info.adim.ndim<<"*"<<info.adim.zdim<<"*"<<info.adim.xdim<<"*"<<info.adim.ydim<<endl;
}
void MultidimArrayTest()
{
	MultidimArray<double> test(3,3);
	test.initRandom(0,1);
	cout<<"In test MultidimArray, ndim is: "<<test.ndim<<endl;
	cout<<"In test MultidimArray, zdim is: "<<test.zdim<<endl;
	cout<<"In test MultidimArray, ydim is: "<<test.ydim<<endl;
	for(int i=0; i<test.ydim; i++){
		for(int j=0; j<test.xdim; j++){
			cout<<dAij(test,i,j)<<" ";
		}
		cout<<endl;
	}

}
