cmake_minimum_required(VERSION 3.10)

project(StalinMergeSortExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(StalinMergeSortLib
    FlexibleArray/FlexibleArray.cpp
    StalinMergeSort/StalinMergeSort.cpp
    UnionOfSovietSocialistRepublics/UnionOfSovietSocialistRepublics.cpp
)

target_include_directories(StalinMergeSortLib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

add_executable(StalinMergeSortExample
    ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp
)

target_link_libraries(StalinMergeSortExample
    PRIVATE
        StalinMergeSortLib
)
