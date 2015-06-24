#!/bin/bash

RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[1;32m'
NC='\033[0m' # No Color

if [ ! -d "./build" ]; then
  printf "${YELLOW}No build directory... Creating one${NC}\n"
  mkdir ./build && cd build
  printf "${YELLOW}Creating Makefile with cmake...\n"
  cmake -G "Unix Makefiles" ..
  cd ..
fi

printf "${YELLOW}Cleaning build directory\n${NC}"
rm -f ./build/*_test_exec 

printf "${YELLOW}Compiling all test files${NC}\n"
make -C ./build
if [ $? -eq 0 ]; then
    printf "${GREEN}Compiled Successfully!${NC}\n\n"
    printf "${YELLOW}Running Tests...${NC}\n"
    for test in `ls build/ | grep _test_exec`; do 
        printf "${YELLOW}${test}${NC}\n"
        test_exec="./build/${test}"
	eval $test_exec
    done
else
    printf "${RED}FAILED TO COMPILE ALL TESTS SEE ERRORS ABOVE${NC}\n"
fi

