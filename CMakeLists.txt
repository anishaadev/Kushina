cmake_minimum_required(VERSION 3.27)
project(Kushina)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE KUNISHA_SRC
        ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE KUNISHA_INCL
        ${CMAKE_SOURCE_DIR}/src/*.hpp)

add_executable(Kushina ${KUNISHA_SRC} ${KUNISHA_INCL})
