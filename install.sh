#!/bin/bash

#compile the shared library
echo "compile the shared library--------------------------"
mkdir -pv build
cd build
cmake -DCMAKE_BUILD_TYPE="Release" ..
make -j4

