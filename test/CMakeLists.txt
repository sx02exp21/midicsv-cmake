include (${CMAKE_ROOT}/Modules/FindBoost.cmake)

set(BOOST_ROOT "E:/x64/Development/DevLibs/boost/boost_1_64_0")
set(BOOST_LIBRARYDIR "E:/x64/Development/DevLibs/boost/boost_1_64_0/stage/lib")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package (Boost 1.64.0 REQUIRED COMPONENTS system filesystem unit_test_framework)
include_directories (${TEST_SOURCE_DIR}/src ${Boost_INCLUDE_DIRS})

add_subdirectory(src)
file(COPY resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# add_definitions (-DBOOST_TEST_DYN_LINK)
# add_executable (TestMidiCSV crc_example.cpp)
# target_link_libraries (TestMidiCSV 
# 	${Boost_FILESYSTEM_LIBRARY} 
# 	${Boost_SYSTEM_LIBRARY}
#         ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
#         )
# add_test (NAME TestCRC COMMAND TestMidiCSV)
