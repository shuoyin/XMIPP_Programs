#ImageIO
This program test some IO functions and structures. 
##API Reference
####ImageInfo
    struct ImageInfo{
      FileName  filename;
      size_t    offset;
      DataType  datatype;
      bool      swap;
      ArrayDim  adim;
    }
####ArrayDim
we assume that a file is n\*z\*x\*y<br />
  `ArrayDim::ArrayDim`: constructor with no arguments, set all member to 0<br />
  `ArrayDim::ndim`: number of images in this file, which is n<br />
  `ArrayDim::zdim`: number of elements in Z, which is z<br />
  `ArrayDim::xdim`: number of elements in X, which is x<br />
  `ArrayDim::ydim`: number of elements in Y, which is y<br />
  `ArrayDim::yxdim`: number of elements in YX, which is y\*x<br />
  `ArrayDim::zyxdim`: number of elements in ZYX, which is z\*y\*x<br />
  `ArrayDim::nzyxdim`: number of elements in NZYX, which is n\*z\*y\*x<br />
  `ArrayDim::operator==(ArrayDim &adim)`: if all member is equal, return true.<br />
####Image<T>
the member of class Image<T><br />
  `void getInfo(ImageInfo &info)`: get image info.<br />
  `MultidimArray data`: public data member, stores image data.<br />
  `DataType datatype()`: get the image file data type. For values of DataType, see <xmipp_datatype.h><br />
  `void getDimensions(ArrayDim &dim)`: get dimension info of the file.<br />
