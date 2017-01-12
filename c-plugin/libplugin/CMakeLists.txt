cmake_minimum_required(VERSION 2.8)
project(libplugin)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/plugin.c)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(
    plugin
    SHARED
    ${SRC})
