# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)



# Collect all the test sources
file(GLOB test_sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
# Compile the tests
add_executable(${CMAKE_PROJECT_NAME}_test ${test_sources})
# Now simply link against gtest or gtest_main as needed
target_link_libraries(${CMAKE_PROJECT_NAME}_test gtest_main ${CMAKE_PROJECT_NAME}_lib)
# Include this directory for includes
target_include_directories(${CMAKE_PROJECT_NAME}_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add the test to the CMake test framework
add_test(NAME ${CMAKE_PROJECT_NAME}_test COMMAND ${CMAKE_PROJECT_NAME}_test)
