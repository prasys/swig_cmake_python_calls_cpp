#!/bin/bash 
# run the commands to build the distribution
mkdir -p output 
cd build
cmake ..
make
mv example.py ../output
mv _example.so ../output
touch ../setup.cfg
if [[ "$(expr substr $(uname -s) 1 5)" == "Linux" ] then
cd ..
cd dist
rename cp36-cp36m-linux_x86_64.whl cp36-cp36m-manylinux_2_17_x86_64.whl  *.whl # TODO: handle dynamic naming but we will fix the python version for this 
fi
cd ..
ls -lrt
python3 setup.py bdist_wheel