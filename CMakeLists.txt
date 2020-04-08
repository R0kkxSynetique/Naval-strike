cmake_minimum_required(VERSION 3.15)
project(bataille_navale C)

set(CMAKE_C_STANDARD 99)

add_executable(bataille_navale main.c MyLibrary/menu.c MyLibrary/menu.h MyLibrary/jouer.c MyLibrary/jouer.h MyLibrary/aide.c MyLibrary/aide.h MyLibrary/options.c MyLibrary/options.h MyLibrary/sauvgarder.c MyLibrary/sauvgarder.h MyLibrary/readscore.c MyLibrary/readscore.h MyLibrary/Utils.c MyLibrary/Utils.h MyLibrary/logs.c MyLibrary/logs.h)