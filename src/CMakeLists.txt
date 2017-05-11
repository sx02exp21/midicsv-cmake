cmake_minimum_required(VERSION 3.8)
# project(MidiCSV)

# set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# midicsv
set(midicsv_INCLUDES .)
set(midicsv_SOURCES midicsv.c midio.c getopt.c)
include_directories(${midicsv_INCLUDES})
add_definitions(-DHAVE_CONFIG_H)
add_executable(midicsv ${midicsv_SOURCES})
# target_link_libraries(midicsv)
add_custom_command(TARGET midicsv POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:midicsv> ${CMAKE_CURRENT_BINARY_DIR}/../${PROJECT_TEST_DIR})

# csvmidi
set(csvmidi_INCLUDES .)
set(csvmidi_SOURCES csv.c csvmidi.c midio.c getopt.c)
include_directories(${csvmidi_INCLUDES})
add_definitions(-DHAVE_CONFIG_H)
add_executable(csvmidi ${csvmidi_SOURCES})
# target_link_libraries(csvmidi)
add_custom_command(TARGET csvmidi POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:csvmidi> ${CMAKE_CURRENT_BINARY_DIR}/../${PROJECT_TEST_DIR})

# Targets, Config and Version
# =============================================================================
install(TARGETS midicsv csvmidi EXPORT MidiCSVTargets RUNTIME DESTINATION bin)

# Install the export set for use with the install-tree
install(EXPORT MidiCSVTargets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# export(TARGETS midicsv csvmidi FILE "${PROJECT_BINARY_DIR}/MidiCSVTargets.cmake")
# export(TARGETS midicsv csvmidi FILE "${PROJECT_CMAKE_DIR}/MidiCSVTargets.cmake")
export(EXPORT MidiCSVTargets FILE "${PROJECT_BINARY_DIR}/MidiCSVTargets.cmake")
export(PACKAGE MidiCSV)

