cmake_minimum_required(VERSION 3.5)
project(MatrixCalc)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optional strict mode
if(STRICT)
  message("-- Enabling strict compilation mode")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add executables
add_executable(MatrixCalc src/main.cpp src/matrix.cpp include/matrix.h)
add_executable(test_exe test/test.cpp src/matrix.cpp)

# Set C++ standard for the targets
set_property(TARGET MatrixCalc PROPERTY CXX_STANDARD 11)
set_property(TARGET test_exe PROPERTY CXX_STANDARD 11)

target_include_directories(test_exe PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/test/catch2)