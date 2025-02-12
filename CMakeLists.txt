cmake_minimum_required(VERSION 3.29)
project(lazyfoo_tut2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

add_executable(lazyfoo_tut2 main.cpp
        GameInstance.cpp
        GameInstance.h
        GameInstance.h
        RenderSystem.cpp
        RenderSystem.h
        Texture.cpp
        Texture.h
        RenderingLayer.cpp
        RenderingLayer.h
        Sprite.cpp
        Sprite.h)
target_link_libraries(lazyfoo_tut2 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES})
