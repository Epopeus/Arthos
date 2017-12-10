include_directories(../src)
add_executable(MaNGOSCleanServerTests_run ServerTests.cpp)
target_link_libraries(MaNGOSCleanServerTests_run MaNGOSCleanServerLib ${CONAN_LIBS})