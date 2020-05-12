cmake_minimum_required(VERSION 3.0)

project(circular LANGUAGES C)

set(SOURCES circular.c)
set(HEADERS circular.h)


set(CMAKE_BUILD_TYPE Release)


add_library(circular)

target_sources(circular PRIVATE ${SOURCES} ${HEADERS})
target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(circular PUBLIC game)

