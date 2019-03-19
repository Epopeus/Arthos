cmake_minimum_required(VERSION 3.13.0)
set(M_PROJECT_NAME Arthos)
project(${M_PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)

enable_testing()

#Conan
execute_process(COMMAND conan install --build=missing --build=outdated -s build_type=Release ${PROJECT_SOURCE_DIR})
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


#Project constants
set(M_SRC_DIR src)
set(M_TESTS_DIR test)
set(M_GAME_DIR game)
set(M_OPS_DIR ops)

# Services/lib registering

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


function(register_lib_tests internal_lib_name lib_name lib_path)
    set(tests_source_dir ${PROJECT_SOURCE_DIR}/${M_TESTS_DIR}/${lib_path}/${lib_name})
    set(executable_name ${internal_lib_name}Tests)

    file(GLOB_RECURSE tests_source_files ${tests_source_dir}/*.h ${tests_source_dir}/*.cpp)
    list(LENGTH tests_source_files tests_source_files_number)

    if (tests_source_files_number EQUAL 0)
        message("No tests registered for lib '${internal_lib_name}' because there are no tests.")
        return()
    endif()

    add_executable(${executable_name} ${tests_source_files})

    target_link_libraries(${executable_name} ${internal_lib_name} ${CONAN_LIBS})
    target_include_directories(${executable_name} PRIVATE ${PROJECT_SOURCE_DIR}/${M_SRC_DIR})

    list(LENGTH tests_source_files tests_source_files_number)
    message("Tests for lib '${internal_lib_name}' registered as '${executable_name}' with ${tests_source_files_number} source files.")
endfunction()

function(register_lib lib_name lib_path)
    message("Registering lib '${lib_name}' with path '${lib_path}' with linked libs '${ARGN}'...")

    set(lib_source_dir ${PROJECT_SOURCE_DIR}/${M_SRC_DIR}/${lib_path}/${lib_name})
    format_linked_libs(formatted_linked_libs "${ARGN}")

    set_internal_lib_name(${lib_name} internal_lib_name)

    file(GLOB_RECURSE lib_source_files ${lib_source_dir}/*.h ${lib_source_dir}/*.cpp)
    list(REMOVE_ITEM lib_source_files ${lib_source_dir}/main.cpp)

    add_library(${internal_lib_name} ${lib_source_files})

    target_link_libraries(${internal_lib_name} ${formatted_linked_libs} ${CONAN_LIBS})
    target_include_directories(${internal_lib_name} PRIVATE ${PROJECT_SOURCE_DIR}/${M_SRC_DIR})

    # Last argument is just in case lib_path is empty
    register_lib_tests(${internal_lib_name} ${lib_name} ${lib_path} "")

    list(LENGTH lib_source_files lib_source_files_number)
    message("Game lib '${lib_name}' registered with internal lib name '${internal_lib_name}' and ${lib_source_files_number} source files.")
endfunction()

function(register_service service_name service_path)
    message("Registering service '${service_name}' with path '${service_path}' with linked libs '${ARGN}'...")

    set(executable_name ${M_PROJECT_NAME}${service_name}d)
    format_linked_libs(formatted_linked_libs "${ARGN}")

    register_lib(${service_name} ${service_path} ${ARGN})

    add_executable(${executable_name} ${PROJECT_SOURCE_DIR}/${M_SRC_DIR}/${service_path}/${service_name}/main.cpp)

    set_internal_lib_name(${service_name} internal_lib_name)

    target_link_libraries(${executable_name} ${internal_lib_name} ${formatted_linked_libs} ${CONAN_LIBS})
    target_include_directories(${executable_name} PRIVATE ${PROJECT_SOURCE_DIR}/${M_SRC_DIR})

    message("Game service '${service_name}' registered as '${executable_name}'.")
endfunction()



message("\n\nPreparing ${M_PROJECT_NAME}...\n")

register_lib("common" "")
register_lib("network" "${M_OPS_DIR}")
register_service("auth" "${M_GAME_DIR}" "common")
register_service("proxy" "${M_OPS_DIR}" "common")

message("${M_PROJECT_NAME} ready.\n\n")