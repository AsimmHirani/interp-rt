cmake_minimum_required(VERSION 3.15)
project(interp_rt C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")


include_directories(include)

add_library(interp_rt src/interp-rt.c include/interp-rt.h)