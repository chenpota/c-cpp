cmake_minimum_required(VERSION 2.8)
project(app)

add_definitions(
    -DMYPLUGIN_PATH="${CMAKE_BINARY_DIR}/libmyplugin/libmyplugin.so")

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../libplugin/include)

set(LIB
    plugin
    dl)

add_executable(
    app
    ${SRC}
)

target_link_libraries(
    app
    ${LIB})
