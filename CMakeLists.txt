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
set(M_PROD_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(M_TESTS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/test)
set(M_GAME_SOURCE_DIR ${M_PROD_SOURCE_DIR}/game)

function(register_game_lib_tests lib_path internal_lib_name)
    set(tests_source_dir ${M_TESTS_SOURCE_DIR}/${lib_path})
    set(executable_name ${internal_lib_name}Tests)

    message("Registering tests for game lib '${internal_lib_name}'...")

    file(GLOB_RECURSE tests_source_files ${tests_source_dir}/*.h ${tests_source_dir}/*.cpp)
    list(LENGTH tests_source_files tests_source_files_number)

    if (tests_source_files_number EQUAL 0)
        message("No tests registered for game lib '${lib_path}' because there are no tests.")
        return()
    endif()

    add_executable(${executable_name} ${tests_source_files})

    target_link_libraries(${executable_name} ${internal_lib_name} ${CONAN_LIBS})
    target_include_directories(${executable_name} PRIVATE ${M_PROD_SOURCE_DIR})

    list(LENGTH tests_source_files tests_source_files_number)
    message("Tests for game lib '${lib_path}' registered as '${executable_name}' with ${tests_source_files_number} source files.")
endfunction()

function(set_internal_lib_name lib_name internal_lib_name)
    set(${internal_lib_name} "${M_PROJECT_NAME}${lib_name}Lib" PARENT_SCOPE)
endfunction()

function(format_linked_libs formatted_linked_libs linked_libs)
    set(listVar "")

    foreach(lib ${linked_libs})
        set_internal_lib_name(${lib} internal_lib_name)
        list(APPEND listVar "${internal_lib_name}")
    endforeach()
    set(${formatted_linked_libs} "${listVar}" PARENT_SCOPE)
endfunction()

function(register_game_lib lib_name lib_path)
    message("Registering game lib '${lib_name}' with linked libs '${ARGN}'...")

    format_linked_libs(formatted_linked_libs "${ARGN}")
    if (lib_path STREQUAL "")
        set(lib_source_dir ${M_PROD_SOURCE_DIR}/${lib_name})
    else()
        set(lib_source_dir ${M_PROD_SOURCE_DIR}/${lib_path}/${lib_name})
    endif()
    set_internal_lib_name(${lib_name} internal_lib_name)

    file(GLOB_RECURSE lib_source_files ${lib_source_dir}/*.h ${lib_source_dir}/*.cpp)
    list(REMOVE_ITEM lib_source_files ${lib_source_dir}/main.cpp)

    add_library(${internal_lib_name} ${lib_source_files})

    target_link_libraries(${internal_lib_name} ${formatted_linked_libs} ${CONAN_LIBS})
    target_include_directories(${internal_lib_name} PRIVATE ${M_PROD_SOURCE_DIR})

    register_game_lib_tests(${lib_name} ${internal_lib_name})

    list(LENGTH lib_source_files lib_source_files_number)
    message("Game lib '${lib_name}' registered with internal lib name '${internal_lib_name}' and ${lib_source_files_number} source files.")
endfunction()

function(register_game_service service_name)
    message("Registering game service '${service_name}' with linked libs '${ARGN}'...")

    set(executable_name ${M_PROJECT_NAME}${service_name}d)
    format_linked_libs(formatted_linked_libs "${ARGN}")

    register_game_lib(${service_name} game ${ARGN})

    add_executable(${executable_name} ${M_GAME_SOURCE_DIR}/${service_name}/main.cpp)

    set_internal_lib_name(${service_name} internal_lib_name)

    target_link_libraries(${executable_name} ${internal_lib_name} ${formatted_linked_libs} ${CONAN_LIBS})
    target_include_directories(${executable_name} PRIVATE ${M_PROD_SOURCE_DIR})

    message("Game service '${service_name}' registered as '${executable_name}'.")
endfunction()

message("\n\nPreparing ${M_PROJECT_NAME}...\n")

register_game_lib("common" "")
register_game_service("auth" "common")

message("${M_PROJECT_NAME} ready.\n\n")