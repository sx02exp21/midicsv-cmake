include (${CMAKE_ROOT}/Modules/CheckIncludeFile.cmake)
# include (${CMAKE_ROOT}/Modules/CheckIncludeFiles.cmake)
# include (${CMAKE_ROOT}/Modules/FindDoxygen.cmake)
# include (${CMAKE_ROOT}/Modules/FindPkgConfig.cmake)

add_compile_options(-Wall)

check_include_file("stdio.h" HAVE_STDIO_H)
check_include_file("stdlib.h" HAVE_STDLIB_H)
check_include_file("string.h" HAVE_STRING_H)
check_include_file("ctype.h" HAVE_CTYPE_H)

if(WIN32 AND NOT CYGWIN)
  check_include_file("fcntl.h" HAVE_FCNTL_H)
  check_include_file("io.h" HAVE_IO_H)
endif()

# Generate config.h file
configure_file(${PROJECT_CMAKE_DIRECTORY}/MidiCSVConfig.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

