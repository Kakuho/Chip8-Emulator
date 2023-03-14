cmake_minimum_required(VERSION 3.10...3.25)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(CHIP8 VERSION 1.0
              DESCRIPTION "CHIP8 Emulator"
              LANGUAGES CXX)
# this 

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANARD_REQUIRED true)

add_executable(Debug main.cpp Test.cpp Test.hpp DebugCPU.cpp DebugCPU.hpp ./../CPU.cpp ./../CPU.hpp ./../MMU.cpp 
  ./../MMU.hpp ./../PixelBuffer.cpp ./../PixelBuffer.hpp 
  ./../System.cpp ./../System.hpp ./../utilities.hpp)
