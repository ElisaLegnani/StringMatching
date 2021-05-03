cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(stringmatching
    VERSION 1.0
    DESCRIPTION "String Matching algorithms"
    LANGUAGES CXX
    )
    
enable_testing()

add_library(algorithms
    src/algos.cpp
    )

target_include_directories(algorithms PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    )

add_executable(stringmatching
    src/string_matching.cpp
    )

target_link_libraries(stringmatching PUBLIC algorithms)

add_executable(algostest
    test/algos.cpp
    )

target_link_libraries(algostest PUBLIC algorithms)

add_test(NAME algostest
    COMMAND algostest 
    )