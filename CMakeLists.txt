# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("DesignPatternsTest")

#include CONFIG files of library in order to import package
list(APPEND CMAKE_PREFIX_PATH "C:/Users/kev/source/cpp_design_patterns/install")
find_package(DesignPatterns_Basic CONFIG REQUIRED)


# A pkg-config module for CMake
# Requires isntallation of pkg-config in cmd (choco)
include(FindPkgConfig)

set(CMAKE_FRAMEWORK_PATH "C:/Users/kev/source/cpp_design_patterns/install/share/pkgconfig")

pkg_check_modules(IDIOMS REQUIRED IMPORTED_TARGET idioms)

pkg_check_modules(DESIGN_CREATIONAL REQUIRED IMPORTED_TARGET GLOBAL creational)

# Include sub-projects.
add_subdirectory ("DesignPatternsTest")