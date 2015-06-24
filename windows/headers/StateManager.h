/*
 * StateManager.h
 *
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
#ifndef StateManager_H
#define StateManager_H

typedef enum state_type {GetUsername,
                    GetPassword,
                    GetColorType,
                    VerifyCredentials,
                    Logging} stateType;

// get the proper question to ask the user
char *getQuestion(stateType state);

// ask the question to the user
void askQuestion(char **question);

// get the user input
char *getResponse();

// check to make sure the username/password entered is not empty or null
char checkValidInput(char *username);

// sets the proper state based on if the should_change value (true or false)
void setState(stateType *state, char should_change);
#endif
