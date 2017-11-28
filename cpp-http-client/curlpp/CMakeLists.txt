cmake_minimum_required(VERSION 3.0)

add_executable(
    a.out
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(
    a.out
    curl
    curlpp)

target_compile_options(
    a.out
    PRIVATE "-std=c++11")

target_compile_definitions(
    a.out
    PRIVATE _GLIBCXX_USE_CXX11_ABI=0)
