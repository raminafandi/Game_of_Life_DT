cmake_minimum_required(VERSION 3.10.2)
cmake_policy(SET CMP0076 NEW)

project(Game_Of_Life_DT LANGUAGES C)

add_subdirectory(game)
add_subdirectory(console)
add_subdirectory(clipped)
add_subdirectory(circular)
add_subdirectory(sdl2)

find_package(Doxygen)

if(DOXYGEN_FOUND)

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

    add_custom_target(docs
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND firefox ${CMAKE_CURRENT_SOURCE_DIR}/Docs/html/index.html  
    )
endif(DOXYGEN_FOUND)

set (FILES_TAR_GZ "${CMAKE_CURRENT_SOURCE_DIR}")

add_custom_target(dist
    COMMAND ${CMAKE_COMMAND} -E tar "cfvz" "Game_Of_Life_DT.tar.gz" "${FILES_TAR_GZ}"
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_CURRENT_SOURCE_DIR}/build/Game_Of_Life_DT.tar.gz
        ${CMAKE_CURRENT_SOURCE_DIR}
    )



set(TEST unit_testing)
add_executable(${TEST})
add_executable(${PROJECT_NAME} main.c)
target_sources(${TEST} PUBLIC unit_testing.c)
target_link_libraries(${TEST} PUBLIC cunit game console clipped circular sdl2)
target_link_libraries(${PROJECT_NAME} PUBLIC  game console clipped circular sdl2)

enable_testing()
add_test(Game_Of_Life_DT ${TEST})

add_custom_target(cover
COMMAND cmake --build . --target test
COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${TEST}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(cover_html
COMMAND cmake --build . --target test
COMMAND gcovr --html --html-detail -o index.html -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${TEST}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

