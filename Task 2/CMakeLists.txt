cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add library
add_library(calculator STATIC calculator.cpp)

# Add executable
add_executable(calculator_exec main.cpp)

# Link library to executable
target_link_libraries(calculator_exec PRIVATE calculator)
