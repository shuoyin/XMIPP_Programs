#include <iostream>
#include <string>
#include <data/xmipp_image.h>
#include <data/metadata_extension.h>

using namespace std;

void test(MetaData &md);

int main(int argc, char**argv)
{
	MetaData md;
	FileName fn;
	fn.compose("classes",argv[1]);
	md.read(fn);

	chdir("/home/yinshuo/XMIPP_exp/2DAnalysis");
	String s;
	md.getValue(MDL_IMAGE, s, 1);
	cout<<s<<endl;
	String cmd = "xmipp_showj "+s;
	system(cmd.c_str()); //this command will block following code
	MDQuery mq;
	cout<<"number of objects: "<<md.countObjects(mq)<<endl;

	Image<double> image;
	image.read(s);
	image.write("test.stk");

	MetaData out;
//	out.aggregate(md, AGGR_COUNT, MDL_REF, MDL_SHIFT_X, MDL_COUNT);
//	out.write("test.xmd");
	return 0;
}

void test(MetaData &md)
{
	double x,y;
	FOR_ALL_OBJECTS_IN_METADATA(md) //loop through all lines
	{
		 md.getValue(MDL_X, x,__iter.objId);
		 md.getValue(MDL_Y, y,__iter.objId);
		 cout<<x<<" "<<y<<" "<<__iter.objIndex<<endl;
	}

	MetaData out;
	out.aggregate(md, AGGR_SUM, MDL_X, MDL_Y, MDL_COUNT);
	out.write("test.xmd");
}
