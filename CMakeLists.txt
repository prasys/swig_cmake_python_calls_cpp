#
#	CMAKELISTS.TXT
#	--------------
#	Copyright (c) 2021 Andrew Trotman
#	Released under the 2-clause BSD license (See:https://en.wikipedia.org/wiki/BSD_licenses)
#
#	Example CMakeLists.txt file to call C++ from Python via Swig
#

#
#	Basic "stuff" needed to get cmake running without warnings
#
cmake_minimum_required(VERSION 3.8)

set(CMAKE_VERBOSE_MAKEFILE on)

cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

#
#	Project
#
project(all)

add_definitions("-Wall -fPIC -Wno-deprecated-declarations")

#
#	Tell cmake that we need swig
#
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
set(SWIG_SOURCE_FILE_EXTENSIONS ".i" ".swg")

#
# Remove some cmake warnings
#
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

#
#	Tell cmake that we need the Python development environment
#
find_package(Python REQUIRED COMPONENTS Interpreter Development)

#
#	Work out which version of Python we're on and set up CMAKE_SWIG appropriately
#
if(Python_VERSION VERSION_GREATER_EQUAL 3)
	message("Building for Python 3")
    set(CMAKE_SWIG_FLAGS -py3 -doxygen)
else()
	message("Building for Python 2")
    set(CMAKE_SWIG_FLAGS -classic -doxygen)
endif()

#
#	Finally, we're on to our program, which is written in C++
#
set_property(SOURCE example.i PROPERTY CPLUSPLUS ON)

#
#	The Python library is called example and made up of example.i and example.cpp
#
swig_add_library(example TYPE MODULE LANGUAGE python SOURCES example.i example.cpp)

#
#   Tell CMAKE that for OSX we need universal binary and enforce it
#

set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "Build architectures for Mac OS X" FORCE)


#
#	Tell CMAKE_SWIG that we have our own include directories
#
set_property(GLOBAL PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)
include_directories(${Python_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

#
#	This Python modile is called 'example'
#
set_property(SOURCE example.i PROPERTY SWIG_MODULE_NAME example)

#
#	Finally tell cmake to use the Python library when linking
#
swig_link_libraries(example ${Python_LIBRARIES})
