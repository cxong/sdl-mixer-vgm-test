cmake_minimum_required(VERSION 3.19)
project(sdl_mixer_vgm_test C)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer 2.8.0...<3.0.0 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(sdl_mixer_vgm_test main.c)

target_link_libraries(sdl_mixer_vgm_test SDL2::SDL2 SDL2_mixer::SDL2_mixer)
