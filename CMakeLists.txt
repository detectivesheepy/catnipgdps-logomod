cmake_minimum_required(VERSION 3.24)

# Force CMake to find Geode if it's installed in the default directory
if(NOT DEFINED GEODE_SDK)
    if(WIN32)
        set(GEODE_SDK "$ENV{LocalAppData}/Geode/sdk")
    elseif(APPLE)
        set(GEODE_SDK "$ENV{HOME}/Library/Application Support/Geode/sdk")
    endif()
endif()

list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK}/cmake")
include(GeodeMod)

# Define your project metadata
project(custom-logo-mod VERSION 1.0.0 LANGUAGES CXX)

# Initialize the Geode Mod
setup_geode_mod(custom-logo-mod)

# Include your source files
target_sources(custom-logo-mod PRIVATE src/main.cpp)
