cmake_minimum_required (VERSION 3.10.0)

project(libstdc++_date VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(date INTERFACE)
target_include_directories(date INTERFACE include)

add_executable(test_date test_date.cpp)
target_link_libraries(test_date date)

add_executable(test_oper_type test_oper_type.cpp)
target_link_libraries(test_oper_type date)
