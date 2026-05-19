cmake_minimum_required(VERSION 3.10)
project(array_prac4 LANGUAGES CXX)
add_executable(${PROJECT_NAME})
# uncomment the following line to use glob to find source files
# file(GLOB_RECURSE SOURCES src/*.cpp)
# then change the following line to use glob to find source files
# target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_sources(${PROJECT_NAME} PRIVATE src/array_prac4.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
