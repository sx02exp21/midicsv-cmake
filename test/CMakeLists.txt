include (${CMAKE_ROOT}/Modules/FindBoost.cmake)

# REQUIRED - use command line -DBOOST_ROOT -DBOOST_LIBRARYDIR options
# set(BOOST_ROOT "E:/x64/Development/DevLibs/boost/boost_1_64_0")
# set(BOOST_LIBRARYDIR "E:/x64/Development/DevLibs/boost/boost_1_64_0/stage/lib")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package (Boost 1.64.0 REQUIRED COMPONENTS system filesystem unit_test_framework)
include_directories (${TEST_SOURCE_DIR}/src ${Boost_INCLUDE_DIRS})

add_subdirectory(src)
file(COPY resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

