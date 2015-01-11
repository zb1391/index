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

UserCredentials *createUserCredentials(char *name, char *pw, char *color);


#endif