cmake_minimum_required(VERSION 3.10.2)
cmake_policy(SET CMP0076 NEW)

project(Game_Of_Life_DT LANGUAGES C)

add_subdirectory(game)
add_subdirectory(console)
add_subdirectory(clipped)
add_subdirectory(circular)
add_subdirectory(sdl2)


set(TEST unit_testing)
add_executable(${TEST})
add_executable(${PROJECT_NAME} main.c)
target_sources(${TEST} PUBLIC unit_testing.c)
target_link_libraries(${TEST} PUBLIC cunit game console clipped circular sdl2)
target_link_libraries(${PROJECT_NAME} PUBLIC  game console clipped circular sdl2)

enable_testing()
add_test(Game_Of_Life_DT ${TEST})

