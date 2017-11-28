cmake_minimum_required(VERSION 3.0)

add_executable(
    a.out
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(
    a.out
    boost_system
    pthread
    boost_thread
    cppnetlib-client-connections
    cppnetlib-uri
    ssl
    crypto)

target_compile_options(
    a.out
    PRIVATE "-std=c++11")

target_compile_definitions(
    a.out
    PRIVATE BOOST_NETWORK_ENABLE_HTTPS)
