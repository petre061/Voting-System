
# List all the library files but exclude main
file(GLOB libs ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
list(REMOVE_ITEM libs ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)

# Compile the library files
add_library(voting-system-library ${libs})

# Build an executable using main.cc
add_executable(voting-system ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)

# Set the voting-system target to put the executable into the main folder
set_target_properties(voting-system
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Link the executable with the library files
target_link_libraries(voting-system LINK_PUBLIC voting-system-library)
