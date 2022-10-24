include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(tests SettingsTest.cpp)

target_link_libraries(tests ${PROJECT_NAME}_lib)