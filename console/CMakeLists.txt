cmake_minimum_required(VERSION 3.0)

project(console LANGUAGES C)

set(SOURCES console.c)
set(HEADERS console.h)


set(CMAKE_BUILD_TYPE Release)


add_library(console)

target_sources(console PRIVATE ${SOURCES} ${HEADERS})
target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(console PUBLIC game)

