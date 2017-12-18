cmake_minimum_required(VERSION 3.7.2)
project(Arthos)
set(CMAKE_CXX_STANDARD 17)

#Conan
execute_process(COMMAND conan install --build=missing --build=outdated -s build_type=Debug ${PROJECT_SOURCE_DIR})
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


#Project constants
set(M_PROD_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(M_TESTS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/test)
set(M_AUTHD_SOURCE_DIR ${M_PROD_SOURCE_DIR}/game/auth)

#Login daemon executable
file(GLOB_RECURSE ArthosAuthdLibSources ${M_AUTHD_SOURCE_DIR}/*.h ${M_AUTHD_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM ArthosAuthdLibSources ${M_AUTHD_SOURCE_DIR}/main.cpp)

add_library(ArthosAuthdLib ${ArthosAuthdLibSources})
add_executable(ArthosAuthd ${M_AUTHD_SOURCE_DIR}/main.cpp)
target_link_libraries(ArthosAuthd ArthosAuthdLib ${CONAN_LIBS})

#World daemon executable


#Tests executable
enable_testing()
file(GLOB_RECURSE ArthosTestsSources ${M_TESTS_SOURCE_DIR}/*.h ${M_TESTS_SOURCE_DIR}/*.cpp)
add_executable(ArthosTests ${ArthosTestsSources})
target_link_libraries(ArthosTests ArthosAuthdLib ${CONAN_LIBS})
target_include_directories(ArthosTests PUBLIC ${M_PROD_SOURCE_DIR})

