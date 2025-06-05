cmake_minimum_required(VERSION 3.10)
project(MySDLProject CXX C)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Include SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(MySDLProject
    ../main.cpp
    ../rectangle.cpp
    ../graobj.cpp
    ../circ.cpp
    ../../sdlinterf.c
)

# Link SDL2 and math
target_link_libraries(MySDLProject
    ${SDL2_LIBRARIES}
    m
)
