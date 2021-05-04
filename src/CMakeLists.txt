cmake_minimum_required(VERSION 3.11.4)

project(find)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

include_directories(unity/include)


add_executable(find main.c file_management.c find_shortest.c interface.c)

add_executable(unit ../unity/unit_tests.c ../unity/unity.c interface.c find_shortest.c file_management.c)


install(TARGETS find RUNTIME DESTINATION bin)

