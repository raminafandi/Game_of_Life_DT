# CMake generated Testfile for 
# Source directory: /home/gunznkodz/Game_of_Life_DT
# Build directory: /home/gunznkodz/Game_of_Life_DT/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Game_Of_Life_DT "unit_testing")
set_tests_properties(Game_Of_Life_DT PROPERTIES  _BACKTRACE_TRIPLES "/home/gunznkodz/Game_of_Life_DT/CMakeLists.txt;34;add_test;/home/gunznkodz/Game_of_Life_DT/CMakeLists.txt;0;")
subdirs("game")
subdirs("console")
subdirs("clipped")
subdirs("circular")
subdirs("sdl2")
