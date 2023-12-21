cmake_minimum_required(VERSION 3.20)
project(nmlib)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(nmlib
        main.cpp
        inc/tensor.h inc/matrix.h inc/vector.h
        test/test_tensor.h test/test_matrix.h)
