# XMIPP_Programs
####This repo keeps my xmipp test programs. My Platform is Ubuntu 14.04LTS
##Introduction to XMIPP
<em>XMIPP</em> is abbreviation of X-window-based Microscopy Image Processing Package.<br />
It's website is http://xmipp.cnb.csic.es/twiki/bin/view/Xmipp/WebHome.<br />
It also provide a set of libraries for common languages like cpp, java, python and matlab. But according to my experience, 
cpp and java have rather complete support form file IO to algorithms.
To obtain full language support, I suggest to compile XMIPP from source.
##Compile XMIPP
#####1. Download XMIPP source package and unzip file.<br />
  `wget http://xmipp.cnb.csic.es/Downloads/Xmipp-3.1-src.tar.gz`<br />
  `tar -xvf Xmipp-3.1-src.tar.gz`
#####2. Install dependencies.
  It needs jdk, python, openmpi, ssl, ncurse and many kinds of packages and dev files. Remeber to chek log file when you 
  encounter an error. You can install these packages at first.
  
    sudo apt-get install build-essential libopenmpi-dev openmpi-bin libx11-dev libfreetype6-dev libpng12-dev libncurses-dev libssl-dev libreadline-dev libxft-dev
#####3. Compile XMIPP
  Change to the root path of xmipp source and run `./install.sh -j n`, where `n` is the number of cpus you want to use.
  If you are lucky enough you only need to complie once. Mostly you will encounter fails because of lacking packages. For 
  these cases, you need to check its log file to find and install the package.
####4. Other things
  If you want to build matlab support, follow the guide on its website :
  http://xmipp.cnb.csic.es/twiki/bin/view/Xmipp/HowToInstall#Compiling_with_MATLAB_support.<br />
  In my case, I can't build matlab support at the first time because lack of `.xmipp_scons.options` file. It doesn't work 
  even if I create this file. After first compile, this file is created then you can modify it as described on its website.<br>
  As such a big program with so many functions and libraries, I can't beleive its documentation is intolerable. Python docs 
  and cpp docs are mixed, even there's no java docs. It's so lucky that I don't use java. And some docs have no contents 
  just a title.<br />
  It seems that <em>XMIPP</em> doesn't use cmake. Because each time I change the config file and recompile, It recompiles all programs.
  
