cmake_minimum_required(VERSION 3.20)

project(best-present-route)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(best-present-route
    src/main.cpp
    third-party/pugixml.cpp
    src/xml_parser.cpp
    src/map_to_grp.cpp
)

target_include_directories(best-present-route PRIVATE
    third-party
    include
)

target_compile_options(best-present-route PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

