cmake_minimum_required(VERSION 3.16)
project(TP_Algorithms_DS_3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(TP_Algorithms_DS_3 STATIC src/ListGraph.cpp src/ArcGraph.cpp src/MatrixGraph.cpp src/SetGraph.cpp)