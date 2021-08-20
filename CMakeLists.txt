cmake_minimum_required(VERSION 2.20)
project(ZeroBuild C)

set(CMAKE_C_STANDARD 11)

# probably can move minirent to add_library but did not do so
# might do in the future?
add_executable(ZeroBuild src/ZeroBuild.c src/Zerobuild.h src/minirent.h src/minirent.c)
