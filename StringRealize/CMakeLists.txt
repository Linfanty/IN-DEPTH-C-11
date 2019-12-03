cmake_minimum_required(VERSION 3.0.0)
project(Demo VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Demo main.cpp StringRealize.h StringRealize.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
