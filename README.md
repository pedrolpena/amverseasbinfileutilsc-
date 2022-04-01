# xbtbinfileutils
A c++ library that contains classes to work wih XBT bin files generated by Amverseas
The libray can encode and decode message types 1, 2, 3 and 4.
A type 4 message is essentially a type 3 message that stores resistace values instead of temperature values.
Storing actual raw data instead of the temperature values is useful for converting data between the different fall rate equations and applying resistance offsets when calibrating hardware configurations.
Type 4 messages are intended to be used during the calibration stage of a setup.



Disclaimer
==========
This repository is a scientific product and is not official communication of the National Oceanic and
Atmospheric Administration, or the United States Department of Commerce. All NOAA GitHub project code is
provided on an ‘as is’ basis and the user assumes responsibility for its use. Any claims against the Department of
Commerce or Department of Commerce bureaus stemming from the use of this GitHub project will be governed
by all applicable Federal law. Any reference to specific commercial products, processes, or services by service
mark, trademark, manufacturer, or otherwise, does not constitute or imply their endorsement, recommendation or
favoring by the Department of Commerce. The Department of Commerce seal and logo, or the seal and logo of a
DOC bureau, shall not be used in any manner to imply endorsement of any commercial product or activity by
DOC or the United States Government.

-----------------------------------
**COMPILING AND USING THE LIBRARY**
------------------------------------
This project was written using elcipse Version: 2019-06 (4.12.0) so you should be able to make changes 
pretty easily this way. The makefiles that are in the Release and Debug directories were created by eclipse.

To compile under Ubuntu 18.04 without eclipse.
install make and g++
```bash
sudo apt update
sudo apt install make cmake g++
```

Create a seperate make project, create a build directory and a unix sub directory and run cmake.

```bash
cd xbtbinfileutils
mkdir -p build/unix
cd build/unix
```
Now you can create a makefile project.
```bash
cmake ../../
```
To compile issue the make command
```bash
make
```

To install 
```bash
sudo make install
```
The development headers will be installed in "/usr/local/include/xbtbinfileutils" and the library
will be installed in "/usr/local/lib/xbtbinfileutils/".

To uninstall issue the following command.
```bash
sudo make uninstall
```

To compile under Windows, make sure you have Cmake, Ninja and MinGW installed and in the path.

```windows
mkdir build
cd build
mkdir win
cd win
cmake -G"Ninja" ..\
ninja
```
Should have created libxbtbinfileutils.dll and libxbtbinfileutils.dll.a

To install open a command prompt with Admin privledges.
```windows
ninja install
```
The development headers will be installed in "C:/Program Files (x86)/xbtbinfileutils/include/xbtbinfileutils" or
"C:/Program Files/xbtbinfileutils/include/xbtbinfileutils" and the library will be installed in "C:/Program Files (x86)/xbtbinfileutils/lib/xbtbinfileutils" or "C:/Program Files/xbtbinfileutils/lib/xbtbinfileutils"

To uninstall issue the following command
```windows
ninja uninstall
```
