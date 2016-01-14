#include <iostream>
#include <data/xmipp_image.h>

using namespace std;

int main()
{
	Image<double> img;
	img.read("smallStack.stk");
	ArrayDim dim;
	img.getDimensions(dim);
	cout<<"Number of images: "<<dim.ndim<<endl;

	return 0;
}
