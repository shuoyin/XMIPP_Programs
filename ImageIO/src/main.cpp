#include <iostream>
#include <data/xmipp_image.h>

using namespace std;

void printInfo(Image<double> &img);
void MultidimArrayTest();

int main()
{
	Image<double> img;
	/*
	 * you can use n@filename format to get specific image
	 * 0@filename represents whole file
	 */
	try{
	img.read("4@smallStack.stk");
	}catch(XmippError){
		cout<<"Can't open file!"<<endl;
		return -1;
	}
	printInfo(img);
	MultidimArrayTest();
	img.write("test.stk",0,true);
	img.write("test.stk",0,true,WRITE_APPEND);

	return 0;
}

/*
 * the test file we use is 4*1*64*64 with respect to n*z*x*y
 * dim.ndim is 4
 * dim.zdim is 1
 * dim.xdim is 64
 * dim.ydim is 64
 * dim.yxdim is 64*64
 * dim.zyxdim is 1*64*64
 * dim.nzyxdim is 4*1*64*64
 */
void printInfo(Image<double> &img)
{
	ImageInfo info;
	img.getInfo(info);
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
