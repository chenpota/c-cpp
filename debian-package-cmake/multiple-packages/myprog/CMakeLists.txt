cmake_minimum_required(VERSION 2.8)
project(myprog)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../libmyutil)

set(LIB
    myutil)

add_executable(
    myprog
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(
    myprog
    ${LIB})

install(TARGET myprog
        RUNTIME DESTINATION bin)
