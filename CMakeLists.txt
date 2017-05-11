cmake_minimum_required(VERSION 3.8)
project(MidiCSV)

#Version Info
set(MIDICSV_MAJOR_VERSION 1)
set(MIDICSV_MINOR_VERSION 1)
set(MIDICSV_PATCH_VERSION 1)
set(MIDICSV_VERSION ${MIDICSV_MAJOR_VERSION}.${MIDICSV_MINOR_VERSION}.${MIDICSV_PATCH_VERSION})

# Project Config Info
# set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# cmake project files
set(PROJECT_CMAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/cmake)
# message(STATUS "CMake Project Source ${PROJECT_CMAKE_DIRECTORY}")
set(PROJECT_TEST_DIR test/resource)

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/MidiCSV)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

# Add sub-directories
add_subdirectory(src)

# Add tests
enable_testing()
add_subdirectory(test)

# Targets, Config and Version
# =============================================================================
# install(TARGETS midicsv csvmidi EXPORT MidiCSV RUNTIME DESTINATION bin)

# export(TARGETS midicsv csvmidi FILE "${PROJECT_BINARY_DIR}/MidiCSVTargets.cmake")
# export(TARGETS midicsv csvmidi FILE "${PROJECT_CMAKE_DIR}/MidiCSVTargets.cmake")
# export(EXPORT MidiCSV FILE "${PROJECT_BINARY_DIR}/MidiCSVTargets.cmake")
# export(PACKAGE MidiCSV)

# Create the MidiCSVConfig.cmake and MidiCSVConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(${PROJECT_CMAKE_DIRECTORY}/MidiCSVConfig.cmake.in "${PROJECT_CMAKE_DIRECTORY}/MidiCSVConfig.cmake" @ONLY)
configure_file(${PROJECT_CMAKE_DIRECTORY}/MidiCSVConfig.cmake.in "${PROJECT_BINARY_DIR}/MidiCSVConfig.cmake" @ONLY)
# ... for the install tree
#set(CONF_INCLUDE_DIRS "\${FOOBAR_CMAKE_DIR}/${REL_INCLUDE_DIR}")
#configure_file(${PROJECT_CMAKE_DIRECTORY}/MidiCSVConfig.cmake.in "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/MidiCSVConfig.cmake" @ONLY)
# ... for both
configure_file(${PROJECT_CMAKE_DIRECTORY}/MidiCSVConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/MidiCSVConfigVersion.cmake" @ONLY)
 
# Install the MidiCSVConfig.cmake and MidiCSVConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/MidiCSVConfig.cmake"
  "${PROJECT_BINARY_DIR}/MidiCSVConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
 
# Install the export set for use with the install-tree
# install(EXPORT MidiCSVTargets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# add MidiCSVConfig.cmake
include(${PROJECT_CMAKE_DIRECTORY}/MidiCSVConfig.cmake)

