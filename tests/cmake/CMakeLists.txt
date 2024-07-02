cmake_minimum_required(VERSION 3.16)

project(tools_c_ut)

include(../../tools/CMakeCommon.cmake)

verifyCppCompiler(8 6)

find_package(Curses REQUIRED)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(../.. ../../tools)

set(CMAKE_EXE_LINKER_FLAGS "-Wl,--export-dynamic,--no-as-needed")
target_link_libraries(${PROJECT_NAME} ${CMAKE_EXE_LINKER_FLAGS} ${GTEST_BOTH_LIBRARIES} Threads::Threads ncursesw SegFault)
