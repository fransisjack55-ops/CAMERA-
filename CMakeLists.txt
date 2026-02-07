# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Project Name
project(StealthCam)

# Define target
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Build DLL
add_library(StealthCamMFSource SHARED
    path/to/source1.cpp
    path/to/source2.cpp
) 
set_target_properties(StealthCamMFSource PROPERTIES 
    OUTPUT_NAME "StealthCamMFSource" 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Build executable
add_executable(StealthCamVCam 
    path/to/executable1.cpp
    path/to/executable2.cpp
) 
set_target_properties(StealthCamVCam PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Include directories 
include_directories(
    path/to/includes
)

# Additional configuration for x64 Windows with MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /EHsc")
    set(CMAKE_CONFIGURATION_TYPES Release)
endif()