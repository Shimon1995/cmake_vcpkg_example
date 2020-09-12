cmake_minimum_required(VERSION 3.18)
project("example" CXX)

include_directories(${PROJECT_SOURCE_DIR}src/)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

file(GLOB_RECURSE Example_SOURCES "src/*.cxx")
file(GLOB_RECURSE Example_HEADERS "src/*.h")

set (Example_INCLUDE_DIRS "")
foreach (_headerFile ${Example_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Example_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Example_INCLUDE_DIRS)

add_executable (example ${Example_SOURCES})
target_include_directories(example PRIVATE ${Example_INCLUDE_DIRS})

find_package(cpr CONFIG REQUIRED)
target_link_libraries(example PRIVATE cpr)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(example PRIVATE fmt::fmt fmt::fmt-header-only)