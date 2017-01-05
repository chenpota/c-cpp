cmake_minimum_required(VERSION 2.8)
project(libmyutil)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR})

add_library(
    myutil
    SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/Util.cpp)

install(TARGETS myutil
        LIBRARY DESTINATION lib)
