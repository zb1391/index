/*
 * UserCredentials.h
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef UserCredentials_H
#define UserCredentials_H

typedef struct user_credentials_t{
  char *username;
  char *password;
  char colorType[20];
}UserCredentials;

UserCredentials *newUserCredentials();

// create a UserCredetntials struct
UserCredentials *createFullUserCredentials(char *name, char *pw, char *color);

// free a UserCredentials struct
void destroyUserCredentials(UserCredentials **userCredentials);


#endif
