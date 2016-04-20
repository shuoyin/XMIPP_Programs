#XMIPP_AlignImage
this program show how to align two images using xmipp libraries.
##How-to
```cpp
//assume that img1 and img2 are MultidimArray<dobule> and M is a Matrix2D<dobule>
//set the logic origin of the image to center of the image
img1.setXmippOrigin();
img2.setXmippOrigin();
double corr;
corr=alignImages(img1, img2, M);
```
* the `setXmippOrigin` function is important, you must call it before align images.
* the first paramter in `alignImages` is reference image, the second image will be modified, and the third paramter `Matrix2D<double> M` is a transformation matrix whose size is 3x3.
* `alignImages` will return a double value which is correlation of the two input images after alignment.