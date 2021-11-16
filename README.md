# swig_cmake_python_calls_cpp
Example of how to use cmake and swig together with C++ to build Python bindings.  This stuff keeps
changing and none of the examples I found worked out of the box on the Mac, so here's one that
works on Mac and Ubuntu with the latest verson of swig and cmake (as of today: 16 November 2021).

Ubunto: You might have to update your version of cmake on Ubuntu, apt does not (did not?) support a high enough
version of cmake for this to work so you might need to remove the apt version and install it with snap:

```
sudo apt remove --purge cmake
hash -r
sudo snap install cmake --classic
```

To use this example after cloning this repo:
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

# Stuff
Copyright (c) 2021 Andrew Trotman.

Released under the 2-clause BSD license (See:[https://en.wikipedia.org/wiki/BSD_licenses](https://en.wikipedia.org/wiki/BSD_licenses))

Fork this repo.
