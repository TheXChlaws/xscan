cmake_minimum_required(VERSION 3.10)
project(xscan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(xscan 
    src/main.cpp
    src/scanner.cpp
    src/banner.cpp
    src/utils.cpp
)

if(WIN32)
    target_link_libraries(xscan)
else()
    target_link_libraries(xscan)
endif()