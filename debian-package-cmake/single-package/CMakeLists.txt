cmake_minimum_required(VERSION 2.8)

project(mytest)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

set(LINK_LIB
    dl)

add_executable(
    ${CMAKE_PROJECT_NAME}
    ${SRC}
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    ${LINK_LIB}
)

install(
    TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin
)
