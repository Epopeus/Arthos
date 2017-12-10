add_library (MaNGOSCleanServerLib Server.cpp Server.h)
add_executable (MaNGOSCleanServer_run main.cpp)
target_link_libraries (MaNGOSCleanServer_run MaNGOSCleanServerLib ${CONAN_LIBS})