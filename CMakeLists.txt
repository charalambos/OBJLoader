cmake_minimum_required(VERSION 3.8)
project(OBJparser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        OBJ.cpp
        OBJ.h
        OBJParser.h
        OBJParser.lex.h
        OBJParser.lex.cpp
        OBJParser.yacc.hpp
        OBJParser.yacc.cpp)

include_directories(.)
include_directories(/usr/include/eigen3)

add_executable(OBJparser ${SOURCE_FILES})
target_link_libraries(OBJparser -lfl)