cmake_minimum_required(VERSION 3.4...3.18)
project(sum)

# The following has been moved to setup.py
# To enable this you'll need a pybind11 submodule
#add_subdirectory(pybind11)
#pybind11_add_module(sum_from_pybind11 src/sum_pybind11.cpp)
#target_include_directories(sum_from_pybind11 PRIVATE src/)
#target_compile_definitions(sum_from_pybind11 PRIVATE VERSION_INFO=0.1)
add_library(sum_from_ctypes MODULE src/sum.c)

