#!/bin/bash 
# run the commands to build the distribution
mkdir -p output 
cd build
cmake ..
make
mv example.py ../output
mv _example.so ../output
touch ../setup.cfg
cd ..
python3 setup.py bdist_wheel
# This hack is needed to make it to work for linux distro -> https://www.python.org/dev/peps/pep-0513/#rationale
# Refer to https://github.com/pypa/manylinux - we target 2_17 (Uubntu 20.04, Fedora 32+ , CentOS 8 etc......)
if [ "$(expr substr $(uname -s) 1 5)" == "Linux" ] 
then
cd dist
rename cp36-cp36m-linux_x86_64.whl cp36-cp36m-manylinux_2_17_x86_64.whl *.whl  # TODO: handle in dynamic way with cp thingy
fi