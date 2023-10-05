cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME calculator)

project(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES
       src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
