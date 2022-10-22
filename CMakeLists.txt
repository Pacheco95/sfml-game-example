cmake_minimum_required(VERSION 3.0)
project(bouncing_ball)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/utils.cpp
        src/GameObject.cpp
        src/Window.cpp
        src/World.cpp
        src/Game.cpp)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
