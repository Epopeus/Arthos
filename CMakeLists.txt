cmake_minimum_required(VERSION 3.13.0)
set(M_PROJECT_NAME Arthos)
project(${M_PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)

enable_testing()

#Conan
execute_process(COMMAND conan install --build=missing --build=outdated -s build_type=Debug ${PROJECT_SOURCE_DIR})
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


#Project constants
set(M_SRC_DIR src)
set(M_TESTS_DIR test)
set(M_GAME_DIR game)
set(M_OPS_DIR ops)

# Services/lib registering

function(register_lib_tests_lib lib_name lib_path lib_dependencies)
    set(tests_source_dir ${PROJECT_SOURCE_DIR}/${M_TESTS_DIR}${lib_path})

    file(GLOB_RECURSE tests_lib_files ${tests_source_dir}/*.h ${tests_source_dir}/*.cpp)
    file(GLOB_RECURSE tests_exe_files ${tests_source_dir}/*Test.cpp)
    list(REMOVE_ITEM tests_lib_files ${tests_exe_files} "")
    list(LENGTH tests_lib_files tests_lib_files_number)

    if (tests_lib_files_number EQUAL 0)
        return()
    endif()

    set(tests_lib_name ${lib_name}TestsLib)

    add_library(${tests_lib_name} ${tests_lib_files})

    target_link_libraries(${tests_lib_name} ${lib_name} ${lib_dependencies})
    target_include_directories(${tests_lib_name} PRIVATE ${PROJECT_SOURCE_DIR}/${M_SRC_DIR})
    message("Tests lib '${tests_lib_name}' registered with ${tests_lib_files_number} source files.")
endfunction()

function(register_lib_tests lib_name lib_path lib_dependencies)
    set(tests_source_dir ${PROJECT_SOURCE_DIR}/${M_TESTS_DIR}${lib_path})
    set(executable_name ${lib_name}Tests)

    foreach(dep ${lib_dependencies})
        set(tests_lib_name ${dep}TestsLib)

        if (TARGET ${tests_lib_name})
            list(APPEND lib_dependencies ${tests_lib_name})
        endif()
    endforeach()

    register_lib_tests_lib(${lib_name} ${lib_path} ${lib_dependencies} "")

    file(GLOB_RECURSE tests_exe_files ${tests_source_dir}/*Test.cpp)
    list(LENGTH tests_exe_files tests_exe_files_number)

    if (tests_exe_files_number EQUAL 0)
        message("No tests registered for lib '${lib_name}' because there are no tests.")
        return()
    endif()

    add_executable(${executable_name} ${tests_exe_files})

    set(tests_lib_name ${lib_name}TestsLib)

    if (TARGET ${tests_lib_name})
        target_link_libraries(${executable_name} ${tests_lib_name})
    else()
        target_link_libraries(${executable_name} ${lib_name} ${lib_dependencies})
    endif()

    target_include_directories(${executable_name} PRIVATE ${PROJECT_SOURCE_DIR}/${M_SRC_DIR})

    message("Tests for lib '${lib_name}' registered as '${executable_name}' with ${tests_exe_files_number} source files.")
endfunction()

function(register_lib lib_name lib_path lib_dependencies)
    message("Registering lib '${lib_name}' with path '${lib_path}' with dependencies '${lib_dependencies}'...")

    set(lib_source_dir ${PROJECT_SOURCE_DIR}/${M_SRC_DIR}${lib_path})

    file(GLOB_RECURSE lib_source_files ${lib_source_dir}/*.h ${lib_source_dir}/*.cpp)
    list(REMOVE_ITEM lib_source_files ${lib_source_dir}/main.cpp)

    add_library(${lib_name} ${lib_source_files})

    target_link_libraries(${lib_name} ${lib_dependencies} ${CONAN_LIBS})
    target_include_directories(${lib_name} PRIVATE ${PROJECT_SOURCE_DIR}/${M_SRC_DIR})

    list(LENGTH lib_source_files lib_source_files_number)
    message("Game lib '${lib_name}' registered with ${lib_source_files_number} source files.")

    register_lib_tests(${lib_name} ${lib_path} ${lib_dependencies} "")
endfunction()

function(register_app app_name app_path app_dependencies)
    message("Registering app '${app_name}' with path '${app_path}' with dependencies '${app_dependencies}'...")

    register_lib(${app_name}Lib ${app_path} ${app_dependencies})

    set(executable_name ${app_name})
    add_executable(${executable_name} ${PROJECT_SOURCE_DIR}/${M_SRC_DIR}${app_path}/main.cpp)

    target_link_libraries(${executable_name} ${app_name}Lib)
    target_include_directories(${executable_name} PRIVATE ${PROJECT_SOURCE_DIR}/${M_SRC_DIR})

    message("Game app '${app_name}' registered as '${executable_name}'.")
endfunction()


message("\n\nPreparing ${M_PROJECT_NAME}...\n")

register_lib("CommonLib" "/common" "")
register_lib("OpsNetworkLib" "/${M_OPS_DIR}/network" "CommonLib")
register_app("AuthApp" "/${M_GAME_DIR}/auth" "CommonLib")
register_app("ProxyApp" "/${M_OPS_DIR}/proxy" "CommonLib")

message("${M_PROJECT_NAME} ready.\n\n")