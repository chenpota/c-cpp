cmake_minimum_required(VERSION 2.8)

project(myprog)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

add_executable(
    ${CMAKE_PROJECT_NAME}
    ${SRC})

install(
    TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin)
