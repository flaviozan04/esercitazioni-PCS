cmake_minimum_required(VERSION 3.20)
project(esercitazione6) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

add_executable(test_uni_edge test_uni_edge.cpp)
add_test(NAME test_uni_edge COMMAND test_uni_edge)

add_executable(test_uni_graph test_uni_graph.cpp)
add_test(NAME test_uni_graph COMMAND test_uni_graph)

enable_testing()