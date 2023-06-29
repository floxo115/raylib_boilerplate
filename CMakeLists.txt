cmake_minimum_required(VERSION 3.25)
project(raylib_boilerplate)

set(CMAKE_CXX_STANDARD 23)

add_executable(raylib_boilerplate main.cpp)
add_executable(tests tests/test.cpp)
add_subdirectory(external/raylib)
target_include_directories(${PROJECT_NAME} PUBLIC external/raylib/src)
target_link_directories(${PROJECT_NAME} PRIVATE external/raylib/build)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

add_subdirectory(external/catch2)
target_include_directories(tests PUBLIC external/catch2/src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_subdirectory(external/eigen)
target_include_directories(raylib_boilerplate PUBLIC external/eigen)
target_include_directories(tests PUBLIC external/eigen)