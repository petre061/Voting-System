

# Set CMake minimum version
cmake_minimum_required (VERSION 3.16.3)

# Set the project name
project(voting-system)

# Add in the source
add_subdirectory(src)

# Add in tests
add_subdirectory(testing)
