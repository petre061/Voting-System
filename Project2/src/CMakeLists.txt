
# List all the library files but exclude main
file(GLOB lib_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
list(REMOVE_ITEM lib_sources ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)

# Compile the library files
add_library(${CMAKE_PROJECT_NAME}_lib ${lib_sources})

# Include this directory for includes
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Build an executable using main.cc
add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)

# Set the voting-system target to put the executable into the main folder
set_target_properties(${CMAKE_PROJECT_NAME}
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Link the executable with the library files
target_link_libraries(${CMAKE_PROJECT_NAME} LINK_PUBLIC ${CMAKE_PROJECT_NAME}_lib)
