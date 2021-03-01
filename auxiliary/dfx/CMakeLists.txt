cmake_minimum_required(VERSION 3.10)
project(dfx)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions(-D_DFX_API)

file(GLOB_RECURSE INC *.h)
file(GLOB_RECURSE SRC *.cpp)

source_group("inc" FILES ${INC})
source_group("src" FILES ${SRC})

add_library(dfx SHARED ${SRC} ${INC})
