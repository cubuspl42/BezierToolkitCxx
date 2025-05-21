cmake_minimum_required(VERSION 3.31)

# Set the project name and version
project(HelloWorld VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(hello_world src/main.cpp)

# Optionally, set properties or configuration if needed
# E.g., enable warnings as errors for stricter compilation
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(hello_world PRIVATE -Wall -Wextra -Wpedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(hello_world PRIVATE /W4 /WX)
endif()
