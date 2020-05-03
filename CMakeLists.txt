cmake_minimum_required(VERSION 3.10.2)
project(Game_Of_Life_DT LANGUAGES C)

add_subdirectory(game)
add_subdirectory(console)
add_subdirectory(clipped)
add_subdirectory(circular)

add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME} PUBLIC game console clipped circular)