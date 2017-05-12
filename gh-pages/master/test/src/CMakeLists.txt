# set(PROJECT_TEST_DIR ../resource)
add_executable (testMidiCSV testcrc32.cpp)
target_link_libraries (testMidiCSV 
	${Boost_FILESYSTEM_LIBRARY} 
	${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
# add_custom_command(TARGET testMidiCSV POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:testMidiCSV> ${PROJECT_TEST_DIR})
add_custom_command(TARGET testMidiCSV POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:testMidiCSV> ../resource)
add_custom_command(TARGET testMidiCSV POST_BUILD COMMAND midicsv test.mid test.csv WORKING_DIRECTORY ../resource COMMENT "Generate test CSV file output") 
add_custom_command(TARGET testMidiCSV POST_BUILD COMMAND csvmidi test.csv csv.mid WORKING_DIRECTORY ../resource COMMENT "Generate test MIDI file output") 
# add_test (NAME TestCRC COMMAND TestMidiCSV WORKING_DIRECTORY ${PROJECT_TEST_DIR})
add_test (NAME TestCRC COMMAND testMidiCSV test.mid csv.mid WORKING_DIRECTORY ../resource)
