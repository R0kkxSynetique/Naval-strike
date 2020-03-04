cmake_minimum_required(VERSION 3.15)
project(bataille_navale C)

set(CMAKE_C_STANDARD 99)

add_executable(bataille_navale main.c menu.c menu.h play.c play.h file.c file.h)