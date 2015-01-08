project("Tester") # This is the name of the project, it is arbitrary

add_executable(tester my_test1.c) # We are creating an executable called 'tester'. it is build by compiling the my_test1.c code

target_link_libraries(tester check m pthread rt) # We need to link some libraries
