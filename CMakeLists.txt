cmake_minimum_required(VERSION 3.16)
project(hold_the_line LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(hold_core
    src/core/terrain.cpp
    src/core/unit.cpp
    src/core/game_state.cpp
)

add_library(hold_systems
    src/systems/turn_system.cpp
)

target_include_directories(hold_core PUBLIC src)
target_include_directories(hold_systems PUBLIC src)

target_link_libraries(hold_systems PUBLIC hold_core)

add_executable(hold_the_line src/main.cpp)

target_link_libraries(hold_the_line PRIVATE hold_systems)
