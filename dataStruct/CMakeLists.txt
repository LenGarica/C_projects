cmake_minimum_required(VERSION 3.25)
project(dataStruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(dataStruct main.cpp SqList/sqlist.h SqList/sqlist.cpp)
