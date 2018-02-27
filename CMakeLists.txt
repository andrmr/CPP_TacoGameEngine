project(sdl2-base-project)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-std=c++14)

find_package(SDL2 REQUIRED)
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

set(ENGINE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Engine)
set(GAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Game)

file(GLOB_RECURSE SOURCE_LIST "*.cpp" "*.hpp" "*.h")

include_directories(
    ${GAME_DIR}
    ${ENGINE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME} ${SOURCE_LIST})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
