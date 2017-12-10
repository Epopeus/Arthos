cmake_minimum_required(VERSION 3.9)
project(MaNGOSClean)

set(CMAKE_CXX_STANDARD 11)

if(NOT EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    execute_process(COMMAND conan install . -s build_type=Debug --install-folder=cmake-build-debug --build WORKING_DIRECTORY ../)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(MaNGOSClean server/main.cpp)

