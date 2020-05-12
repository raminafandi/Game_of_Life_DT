cmake_minimum_required(VERSION 3.0)

project(clipped LANGUAGES C)

set(SOURCES clipped.c)
set(HEADERS clipped.h)


set(CMAKE_BUILD_TYPE Release)


add_library(clipped)

target_sources(clipped PRIVATE ${SOURCES} ${HEADERS})
target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(clipped PUBLIC game)

