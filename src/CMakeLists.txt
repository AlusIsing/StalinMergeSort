cmake_minimum_required(VERSION 3.10)

project(StalinMergeSortExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(StalinMergeSortExample
    ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp
)

target_link_libraries(StalinMergeSortExample
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/
)
