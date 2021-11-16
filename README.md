# swig_cmake_python_calls_cpp
Example of how to use cmake and swig together with C++ to build Python bindings

To use this example:
```
cd build
cmake ..
make
```

Then to test this example from the build directory:
```
python3 ../test.py
```

The output should be:
```
24
Hello World
```
