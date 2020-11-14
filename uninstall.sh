#!/bin/bash

#uninstall shared lib
rm -r build

#uninstall template file
cd template
make clean

#uninstall grid generator
cd ../grids/1d
rm -f 1Dmesh

#uninstall grid support tool
cd ../tools
./uninstall.sh
