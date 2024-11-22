#!/bin/sh

#first parameter is the name of the executable
EXE=$1

if [ "$EXE" = "" ]; then EXE="FSCOPE";fi

#compiler,: g++, icc, ...
COMP=g++
#compiler flags
CFLAGS=-O3 -lm -fopenmp
# shared object / dll filename
SO=fluctuoscope_extC.so

$COMP AGM_sfunctions.cpp fileutils.cpp stringutils.cpp paramfile.cpp fluctuoscope.cpp -c  $CFLAGS
 
$COMP main.cpp fluctuoscope.o  AGM_sfunctions.o fileutils.o stringutils.o paramfile.o $CFLAGS -o ../$EXE

# For compiling a shared object to use functions in e.g. python ctypes module
$COMP -shared -o $SO -fPIC AGM_sfunctions.cpp fileutils.cpp stringutils.cpp paramfile.cpp
fluctuoscope.cpp $CFLAGS -static