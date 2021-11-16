cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

project(all)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
set(SWIG_SOURCE_FILE_EXTENSIONS ".i" ".swg")

find_package(Python REQUIRED COMPONENTS Interpreter Development)

if(Python_VERSION VERSION_GREATER_EQUAL 3)
	message("Building for Python 3")
    set(CMAKE_SWIG_FLAGS -py3)
else()
	message("Building for Python 2")
    set(CMAKE_SWIG_FLAGS -classic)
endif()

swig_add_library(example TYPE MODULE LANGUAGE python SOURCES example.i example.cpp)
set_property(SOURCE example.i PROPERTY CPLUSPLUS ON)
set_property(GLOBAL PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)
set_property(SOURCE example.i PROPERTY SWIG_MODULE_NAME example)

include_directories(${Python_INCLUDE_DIRS})
swig_link_libraries(example ${Python_LIBRARIES})
