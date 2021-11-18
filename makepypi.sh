 #!/bin/bash 
cd build
cmake ..
make
mv example.py ..
mv _example.so ..
touch ../setup.cfg # dummy file for now - but will use it for config os platform
python3 ../setup.py sdist #