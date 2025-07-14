cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(run)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY "https://github.com/nlohmann/json.git"
  GIT_TAG "v3.11.3")
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.0)
FetchContent_MakeAvailable(raylib)

add_executable(
  run 
    src/modifiers/foodModifier.cpp 
    src/units/settler.cpp 
    src/ttp.cpp
    src/app/menu.cpp 
    src/app/app.cpp 
    src/app/game.cpp
    src/states/stateMachine.cpp
    src/states/gameState.cpp
    src/states/mainMenuState.cpp
)

target_link_libraries(run PRIVATE nlohmann_json::nlohmann_json raylib)

target_include_directories(run PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")
