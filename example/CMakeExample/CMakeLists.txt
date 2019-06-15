cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Release)

project(CMakeExample)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../src/CMakeLists.txt)

add_executable(${PROJECT_NAME} "main.cpp" "testwindow.cpp" ${NUKLEAR_CPP_SOURCE_FILES})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -mwindows -mthreads -DWIN32")
target_link_libraries(${PROJECT_NAME} user32.lib gdi32.lib Msimg32.lib d3d9.dll)
target_link_libraries(${PROJECT_NAME} -static gcc stdc++ winpthread -dynamic)