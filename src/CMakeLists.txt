cmake_minimum_required(VERSION 3.11.4)

project(find)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")


add_executable(find main.c file_management.c find_shortest.c interface.c)


install(TARGETS find RUNTIME DESTINATION bin)
