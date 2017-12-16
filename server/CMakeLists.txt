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
set(M_LOGIND_SOURCE_DIR ${M_PROD_SOURCE_DIR}/daemons/logind)

#Login daemon executable
file(GLOB_RECURSE ArthosLogindLibSources ${M_LOGIND_SOURCE_DIR}/*.h ${M_LOGIND_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM ArthosLogindLibSources ${M_LOGIND_SOURCE_DIR}/main.cpp)

add_library(ArthosLogindLib ${ArthosLogindLibSources})
add_executable(ArthosLogind ${M_LOGIND_SOURCE_DIR}/main.cpp)
target_link_libraries(ArthosLogind ArthosLogindLib ${CONAN_LIBS})

#World daemon executable


#Tests executable
enable_testing()
file(GLOB_RECURSE ArthosTestsSources ${M_TESTS_SOURCE_DIR}/*.h ${M_TESTS_SOURCE_DIR}/*.cpp)
add_executable(ArthosTests ${ArthosTestsSources})
target_link_libraries(ArthosTests ArthosLogindLib ${CONAN_LIBS})
target_include_directories(ArthosTests PUBLIC ${M_PROD_SOURCE_DIR})

