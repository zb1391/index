project("Tester") # This is the name of the project, it is arbitrary

# Test Example
add_executable(tester_exec my_test1.c)
target_link_libraries(tester_exec check m pthread rt) # We need to link some libraries

# UserCredentials Tests
add_executable(usercredentials_test_exec ../lib/UserCredentials.c unit_tests/usercredentials_test.c)
target_link_libraries(usercredentials_test_exec check m pthread rt)

# DataPackager Tests
add_executable(datapackager_test_exec ../lib/UserCredentials.c ../lib/DataPackager.c unit_tests/datapackager_test.c)
target_link_libraries(datapackager_test_exec check m pthread rt yaml)

# StateManager Tests
add_executable(statemanager_test_exec ../lib/StateManager.c unit_tests/statemanager_test.c)
target_link_libraries(statemanager_test_exec check m pthread rt)
