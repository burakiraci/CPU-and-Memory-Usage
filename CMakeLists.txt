cmake_minimum_required(VERSION 3.5)

project(cpu_usage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpu_usage main.cpp; cpu_usage.h;system_cpu_usage.h;cpu_usage.cpp;system_cpu_usage.cpp;memory_usage.cpp;memory_usage.h;system_memory_usage.cpp;system_memory_usage.h)

install(TARGETS cpu_usage
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
