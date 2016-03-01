#include <iostream>
#include <string>
#include <data/xmipp_image.h>
#include <data/metadata_extension.h>

using namespace std;

int main()
{
	chdir("/home/yinshuo/XMIPP_exp/2DAnalysis");

	String blockName[]={
			"class000001_images",
			"class000002_images",
			"class000003_images",
			"class000004_images",
			"class000005_images",
			"class000006_images",
			"class000007_images",
			"class000008_images"
	};
	FileName fn("/home/yinshuo/XMIPP_exp/2DAnalysis/2D/CL2D/run_001/extra/level_02/level_classes.xmd");

	FileName classes;
	classes.compose("classes", fn);
	MetaData md;
	md.read("test.xmd");
	int c;
	md.getValue(MDL_CLASS_COUNT, c, 1);
	/*
	int classCount[8];
	int i=0;
	FOR_ALL_OBJECTS_IN_METADATA(md){
		md.getValue(MDL_CLASS_COUNT, classCount[i], __iter.objId);
		i++;
	}
	for(int i=0; i<8; i++) cout<<classCount[i]<<" ";

	MultidimArray<double> simlarity(500,500);
	*/
	return 0;
}
