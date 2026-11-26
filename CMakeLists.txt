cmake_minimum_required(VERSION 3.20)

# Nom du projet
project(lane_detection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)

add_executable(lane_detection src/main.cpp)

target_include_directories(lane_detection PRIVATE include)

target_link_libraries(lane_detection PRIVATE ${OpenCV_LIBS})

target_compile_options(lane_detection PRIVATE
    -Wall -Wextra -Wconversion -Wsign-conversion -Werror)