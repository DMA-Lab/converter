cmake_minimum_required(VERSION 3.30)
project(graph_converter)

set(CMAKE_CXX_STANDARD 20)

add_executable(convert_to_metis_file plain_to_metis.cpp
        plain.cpp
        graph.cpp
        metis_graph.h
        metis_graph.cpp)

