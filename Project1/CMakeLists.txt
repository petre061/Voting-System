
# Set CMake minimum version
cmake_minimum_required (VERSION 3.16.3)

# Set the C++ standard to 20
set(CMAKE_CXX_STANDARD 20)

# Set the project name
project(voting_system)

# Add in the source
add_subdirectory(src)

# Add in tests
enable_testing()
add_subdirectory(testing)
