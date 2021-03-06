cmake_minimum_required(VERSION 3.20)
project(trees)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -std=c++11 -g")

set(trees_bin_dir ${CMAKE_SOURCE_DIR}/bin)
set(trees_bin_include_dirs ${CMAKE_SOURCE_DIR}/src)

include_directories(${trees_bin_include_dirs})

set(source_files
        src/trees/binary_search_tree.h
        src/trees/binary_tree.h
        src/trees/timer.cc
        src/trees/timer.h)

set(test_files
        src/trees/binary_search_tree_test.cc)

add_executable(trees.out test/main.cc ${source_files})



# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(
        tests
        ${test_files}
        ${source_files}
)
target_link_libraries(tests gtest_main)


set_target_properties(tests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${tree_bin_dir}")

set_target_properties(trees.out
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${tree_bin_dir}")


