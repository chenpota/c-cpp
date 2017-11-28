cmake_minimum_required(VERSION 3.0)

add_executable(
    a.out
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(
    a.out
    boost_system
    crypto
    ssl
    cpprest)

target_compile_options(
    a.out
    PRIVATE "-std=c++11")
