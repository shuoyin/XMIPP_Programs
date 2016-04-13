all: newtest

newtest: NetSim.o test.o
	g++ -L/home/yinshuo/usr/xmipp/lib NetSim.o test.o -lXmippData -lXmippClassif -lXmippDimred -lXmippExternal -ltiff -o newtest

test.o: test.cpp
	g++ -I/home/yinshuo/usr/xmipp -I/home/yinshuo/usr/xmipp/libraries -I/home/yinshuo/us/xmipp/external -c test.cpp -L/home/yinshuo/usr/xmipp/lib  -lXmippData -lXmippClassif -lXmippDimred -lXmippExternal -lXmippInterface -lXmippSqliteExt -lXmippParallel -lXmippRecons -lXmippJNI -ltiff -o test.o

NetSim.o: NetSim.cpp
	g++ -I/home/yinshuo/usr/xmipp -I/home/yinshuo/usr/xmipp/libraries -I/home/yinshuo/us/xmipp/external -c NetSim.cpp -L/home/yinshuo/usr/xmipp/lib  -lXmippData -lXmippClassif -lXmippDimred -lXmippExternal -lXmippInterface -lXmippSqliteExt -lXmippParallel -lXmippRecons -lXmippJNI -ltiff -o NetSim.o

clean:
	rm *.o newtest