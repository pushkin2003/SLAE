cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE PROJECT_SOURCES *.h *.cpp *.hpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

add_library(project ${PROJECT_SOURCES})
target_link_libraries(project PUBLIC )

target_include_directories(project PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})