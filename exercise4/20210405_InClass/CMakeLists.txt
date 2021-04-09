cmake_minimum_required(VERSION 3.17)
project(20210405_InClass C)

set(CMAKE_C_STANDARD 99)

add_executable(20210405_InClass main.c func_ptr_examples/func_pointer.c func_ptr_examples/func_pointer.h func_ptr_examples/comparators.c func_ptr_examples/comparators.h pretty_print.c pretty_print.h)