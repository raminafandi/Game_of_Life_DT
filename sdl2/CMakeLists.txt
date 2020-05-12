cmake_minimum_required(VERSION 3.0)

project(sdl2 LANGUAGES C)

set(SOURCES sdl2.c)
set(HEADERS sdl2.h)


set(CMAKE_BUILD_TYPE Release)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})


add_library(sdl2)

target_sources(sdl2 PRIVATE ${SOURCES} ${HEADERS})
target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sdl2 PUBLIC ${SDL2_LIBRARIES} game)

