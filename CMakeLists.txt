cmake_minimum_required(VERSION 3.22)
project(Vlasolver CXX)

# options
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# find required packages
find_package(Kokkos REQUIRED)
find_package(KokkosKernels REQUIRED)
find_package(OpenMP REQUIRED)
find_package(HighFive REQUIRED)

# create the core library as interface (header-only)
add_library(vlasolver INTERFACE)
target_include_directories(vlasolver
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(vlasolver INTERFACE Kokkos::kokkos KokkosKernels::kokkoskernels HighFive INIReader)

# set common compiler options
target_compile_features(vlasolver INTERFACE cxx_std_20)

# print helpful information when configuration is done
message(STATUS "")
message(STATUS "=== Vlasolver Configuration Summary ===")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "This snapshot provides the header-only framework target `vlasolver`.")
message(STATUS "=======================================")
message(STATUS "")
