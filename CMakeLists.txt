cmake_minimum_required(VERSION 3.15)
project(interp_rt C)

set(CMAKE_C_STANDARD 11)

add_library(interp_rt library.c library.h)