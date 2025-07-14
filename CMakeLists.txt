cmake_minimum_required(VERSION 3.7)

project(RGB)

find_package(SFML COMPONENTS window graphics audio system REQUIRED)

add_definitions(-DASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(RGB main.cpp
)

target_link_libraries(RGB
    sfml-graphics sfml-audio ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}
)
