cmake_minimum_required(VERSION 3.20)
project(esercitazione6) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

add_executable(test_grad_coniug  test_grad_coniug.cpp)
add_test(NAME test_grad_coniug COMMAND test_grad_coniug )


enable_testing()