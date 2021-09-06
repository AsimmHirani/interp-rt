cmake_minimum_required(VERSION 3.15)
project(interp_rt)

set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Os")

include(lib/libfixmath/libfixmath.cmake)
include_directories(include lib)



add_library(interp_rt STATIC src/interp-rt.c src/interp-rt.h)
add_dependencies(interp_rt libfixmath)
add_executable(interp_rt_tester src/tester/tester.cpp src/tester/test.c src/tester/test.h )
target_link_libraries(interp_rt libfixmath)