
cmake_minimum_required (VERSION 3.8)

project ("LinearOptimization")


add_executable (LinearOptimization "LinearOptimization.cpp" "LinearOptimization.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LinearOptimization PROPERTY CXX_STANDARD 20)
endif()


