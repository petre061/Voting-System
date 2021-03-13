
option(BUILD_DOCUMENTATION "Build Doxygen documentation" ON)


find_package(Doxygen)

if (DOXYGEN_FOUND)
  
  set(DOXYGEN_OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

  # Modify Doxyfile.in into Doxyfile
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${DOXYGEN_OUTPUT} @ONLY)

  add_custom_target(documentation ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUTPUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating Doxygen documentation"
    VERBATIM)

else (DOXYGEN_FOUND)
  message("Doxygen not found. Doxygen is necessary to build documentation")
endif (DOXYGEN_FOUND)
