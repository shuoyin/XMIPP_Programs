#include <iostream>
#include <data/xmipp_image.h>

using namespace std;

void ArrayDimTest(Image<double> &img);
int main()
{
	Image<double> img;
	img.read("smallStack.stk");
	ArrayDimTest(img);

	return 0;
}
void ArrayDimTest(Image<double> &img)
{
	ArrayDim dim;
	img.getDimensions(dim);
	cout<<"Number of images: "<<dim.ndim<<endl;
	cout<<"Number of elements in Z: "<<dim.zdim<<endl;
	cout<<"Number of elements in Y: "<<dim.ydim<<endl;
	cout<<"Number of elements in X: "<<dim.xdim<<endl;
	cout<<"Number of elements in YX: "<<dim.yxdim<<endl;
	cout<<"Number of elements in ZYX: "<<dim.zyxdim<<endl;
	cout<<"Number of elements in NZYX: "<<dim.nzyxdim<<endl;
}
