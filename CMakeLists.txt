cmake_minimum_required(VERSION 3.10...3.25)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(CHIP8 VERSION 1.0
              DESCRIPTION "CHIP8 Emulator"
              LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANARD_REQUIRED true)

# Opengl, glad and glfw options.

set(OpenGL_GL_PREFERENCE "GLVND")

include_directories(./glad/include/glad)
include_directories(./glad/include/KHR)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(CHIP8 main.cpp CPU.cpp CPU.hpp MMU.cpp 
  MMU.hpp PixelBuffer.cpp PixelBuffer.hpp GraphicsManager.cpp
  GraphicsManager.hpp System.cpp System.hpp utilities.hpp
  ./glad/src/glad.c)

# linking libraries

target_link_libraries(CHIP8 glfw)

target_link_libraries(CHIP8 OpenGL::GL)
