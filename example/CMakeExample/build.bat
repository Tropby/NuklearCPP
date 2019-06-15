del cmake_install.cmake
del CMakeCache.txt
rmdir /S /Q CMakeFiles
del Makefile
del CMakeExample.exe

set PATH=%PATH%;F:\Qt\Tools\mingw530_32\bin;C:\Program Files\CMake\bin

cmake . -G "MinGW Makefiles"

mingw32-make

pause