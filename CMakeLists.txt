cmake_minimum_required(VERSION 3.24)

# Load the official Geode SDK framework tools automatically provided by the cloud runner
include(GeodeMod)

# Define your project properties matching your mod configuration definitions
project(catnipgdps-logo VERSION 1.0.0 LANGUAGES CXX)

# Package the asset rules and compile configurations
setup_geode_mod(catnipgdps-logo)

# Compile your core C++ main execution file
target_sources(catnipgdps-logo PRIVATE src/main.cpp)
