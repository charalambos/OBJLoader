cmake_minimum_required(VERSION 3.8)
project(OBJLoader)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        OBJ.cpp
        OBJ.h
        OBJLoader.h
        OBJLoader.lex.h
        OBJLoader.lex.cpp
        OBJLoader.yacc.hpp
        OBJLoader.yacc.cpp)

include_directories(.)
include_directories(/usr/include/eigen3)

add_executable(OBJLoader ${SOURCE_FILES})
target_link_libraries(OBJLoader)