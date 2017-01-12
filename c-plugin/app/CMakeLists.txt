cmake_minimum_required(VERSION 2.8)
project(app)

add_definitions(
    -DMYPLUGIN_PATH="${CMAKE_BINARY_DIR}/libplugin/libplugin.so")

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

set(LIB
    dl)

add_executable(
    app
    ${SRC}
)

target_link_libraries(
    app
    ${LIB})
