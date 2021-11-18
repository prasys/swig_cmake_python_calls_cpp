 #!/bin/bash 
cd build
cmake ..
make
mv example.py ..
if [ "$(uname)" == "Darwin" ]; then
    #mv _example.so ..
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    mv _example.so
touch ../setup.cfg # dummy file for now - but will use it for config os platform
python3 ../setup.py sdist #