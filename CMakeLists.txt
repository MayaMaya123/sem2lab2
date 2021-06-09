cmake_minimum_required(VERSION 3.17)
project(sem2lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(sem2lab2 main.cpp dynamic_array.cpp dynamic_array.h linked_list.cpp linked_list.h sequence.h linked_list_sequence.h array_sequence.h vector.h square_matrix.h Menu_for_vectors_and_matrix.h ThorowOutOfRange.h)
add_executable(test test.cpp dynamic_array.cpp dynamic_array.h linked_list.cpp linked_list.h sequence.h)