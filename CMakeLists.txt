cmake_minimum_required(VERSION 3.0)
project(bouncing_ball)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(test)

add_library(${PROJECT_NAME}_lib
        src/utils.cpp
        src/GameObject.cpp
        src/Window.cpp
        src/World.cpp
        src/Game.cpp
        src/Settings.cpp)

target_link_libraries(${PROJECT_NAME}_lib ${CONAN_LIBS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

