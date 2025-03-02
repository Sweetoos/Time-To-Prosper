cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(run)

include_directories(${CMAKE_SOURCE_DIR}/lib/json/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/include)

add_executable(run
    src/modifiers/foodModifier.cpp
    src/units/settler.cpp
    src/menu.cpp
    src/ttp.cpp
)

target_include_directories(run PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")