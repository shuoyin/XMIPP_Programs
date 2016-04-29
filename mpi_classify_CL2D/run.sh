if [ ! "$1" ]; then
	echo "Please enter the root name!";
	exit 1;
fi
mpirun -np 8 --bynode CL2D -i Images/Alignment/images.xmd --odir Run --oroot $1  --nref 8 --iter 10  --nref0 3 --neigh 8
