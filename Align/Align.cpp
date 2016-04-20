#include <data/xmipp_image.h>
#include <data/filters.h>
#include <data/polar.h>

using namespace std;

int main()
{
	Image<double> img1, img2;
	img1.read("000001@/home/yinshuo/Datasets/ph_project.stk");
	img2.read("000060@/home/yinshuo/Datasets/ph_project.stk");

	img1().setXmippOrigin();
	img2().setXmippOrigin();
	
	Matrix2D<double> M;
	double corr;

	corr=alignImages(img1.data, img2.data, M);
	cout<<"correlation is: "<<corr<<endl;
	cout<<M<<endl;

	img2.write("after.xmp");

	return 0;
}