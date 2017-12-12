cmake_minimum_required(VERSION 3.9)
project(MaNGOSClean)
set(CMAKE_CXX_STANDARD 17)

#Conan
execute_process(COMMAND conan install . -s build_type=Debug --install-folder=cmake-build-debug --build=missing --build=outdated  WORKING_DIRECTORY ../)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
#We have to manually remove libraries from Boost (specified in [options] in conanfile.txt) because of a Conan bug
#See https://github.com/lasote/conan-boost/issues/59
list(REMOVE_ITEM CONAN_LIBS boost_unit_test_framework)


#Project constants
set(M_PROD_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(M_TESTS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/test)
set(M_LOGIND_SOURCE_DIR ${M_PROD_SOURCE_DIR}/daemons/logind)

#Login daemon executable
file(GLOB_RECURSE MaNGOSCleanLogindLibSources ${M_LOGIND_SOURCE_DIR}/*.h ${M_LOGIND_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM MaNGOSCleanLogindLibSources ${M_LOGIND_SOURCE_DIR}/main.cpp)

add_library(MaNGOSCleanLogindLib ${MaNGOSCleanLogindLibSources})
add_executable(MaNGOSCleanLogind ${M_LOGIND_SOURCE_DIR}/main.cpp)
target_link_libraries(MaNGOSCleanLogind MaNGOSCleanLogindLib ${CONAN_LIBS})

#World daemon executable


#Tests executable
enable_testing()
file(GLOB_RECURSE MaNGOSCleanTestsSources ${M_TESTS_SOURCE_DIR}/*.h ${M_TESTS_SOURCE_DIR}/*.cpp)
add_executable(MaNGOSCleanTests ${MaNGOSCleanTestsSources})
target_link_libraries(MaNGOSCleanTests MaNGOSCleanLogindLib ${CONAN_LIBS})
target_include_directories(MaNGOSCleanTests PUBLIC ${M_PROD_SOURCE_DIR})

