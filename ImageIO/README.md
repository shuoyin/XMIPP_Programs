#ImageIO
This program test some IO functions and structures. 
##Function Usage
####Read Image
we use `read` to read files<br />

    Image<double> img;
    img.read(filename);
If file doesn't exeists, this function will raise a `XmippError`<br />
If you want to read the header only, then use `img.read(filename, HEADER);`. If you only read 
the header, then you can't acquire data by using `MultidimArray<double> data = img.data`. That will 
cause segmentation fault.<br />
####Write Image
We can use `Image<T>::write` to write images into file.<br />

    void write(const FileName &name="", size_t select_img = ALL_IMAGES, bool isStack=false,
               int mode=WRITE_OVERWRITE,CastWriteMode castMode = CW_CAST, int _swapWrite = 0);
This is general write function. `select_img`=the silce you want to write. In xmipp, the word `slice` means 
a three dimension matrix. The argument `int mode` can be these values:<br />

    typedef enum
    {
    WRITE_READONLY,   //only can read the file
    WRITE_OVERWRITE, //forget about the old file and overwrite it
    WRITE_REPLACE,   //replace a particular object by another
    WRITE_APPEND,    //append and object at the end of a stack, so far can not append stacks
    WRITE_LAST_LABEL                       // **** NOTE ****: Do keep this label always at the end
    // it is here for looping purposes
    } WriteMode;
####MultidimArray
#####Constructor
Constructors of class `MultidimArray` are overload functions. Some are:

    MultidimArray() //empty constructor, size is 0
    MultidimArray(size_t Ndim, int Zdim, int Ydim, int Xdim) //size is Ndim*Zdim*Ydim*Xdim
    MultidimArray( int Zdim, int Ydim, int Xdim) //size is 1*Zdim*Ydim*Xdim
    MultidimArray(int Ydim, int Xdim) //size is 1*1Ydim*Xdim
    MultidimArray(int Xdim) //size is 1*1*1*Xdim
#####Access pixels
There are some macros defined in *\<multidim_array.h\>* to access pixels, like `dAkij`, `dAij`, `DIRECT_A3D_ELEM`, 
`DIRECT_A2D_ELEM`. Besides, there is overloaded operator() to access pixels. If you look at *\<multidim_array.h\>*, 
you will find that all these methods have use `MultidimArray::data` which is a pointer points to data. So, we have:<br />
Suppose we create a 3*3 matrix and initialize it:<br />

    MultidimArray<double> test(3,3);
    test.initRandom(0,1);
Actually we have created a 1\*1\*3\*3 which is a four dimension matrix. So, we can access pixel at 
row i, colj, using `dAij(test,i,j)` or `dAkij(test,1,i,j)` or `test(i,j)` or `test(1,i,j)` or other methods.
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
