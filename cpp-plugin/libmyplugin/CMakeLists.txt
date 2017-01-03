cmake_minimum_required(VERSION 2.8)
project(libplugin)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MyPlugin.cpp)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../libplugin/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(LIB
    plugin)

add_library(
    myplugin
    SHARED
    ${SRC})

target_link_libraries(
    myplugin
    ${LIB})
