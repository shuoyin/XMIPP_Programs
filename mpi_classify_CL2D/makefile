all: CL2D

CL2D: CL2D_main.o NetSim.o
	g++ -o CL2D NetSim.o CL2D_main.o -L/home/yinshuo/usr/xmipp/lib -L/usr/lib/openmpi/lib -lXmippData -lXmippClassif -lXmippDimred -lXmippExternal -lXmippParallel -lXmippRecons -ltiff -lmpi -lmpi_cxx

CL2D_main.o: mpi_classify_CL2D_main.cpp mpi_classify_CL2D.h NetSim.h
	g++ -I/home/yinshuo/usr/xmipp/libraries -I/home/yinshuo/usr/xmipp/externals -I/home/yinshuo/usr/xmipp -I/usr/include/openmpi -c mpi_classify_CL2D_main.cpp -L/home/yinshuo/usr/xmipp/lib -lXmippData -lXmippClassif -ltiff -lXmippExternal -lXmippParallel -lXmippRecons -L/usr/lib/openmpi/lib -lmpi -lmpi_cxx -o CL2D_main.o

NetSim.o: NetSim.h NetSim.cpp
	g++ -I/home/yinshuo/usr/xmipp -I/home/yinshuo/usr/xmipp/libraries -I/home/yinshuo/us/xmipp/external -c NetSim.cpp -L/home/yinshuo/usr/xmipp/lib  -lXmippData -lXmippClassif -lXmippDimred -lXmippExternal -lXmippInterface -lXmippSqliteExt -lXmippParallel -lXmippRecons -lXmippJNI -ltiff -o NetSim.o

clean:
	rm *.o CL2D