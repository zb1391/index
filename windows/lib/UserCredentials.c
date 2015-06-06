#include "../headers/UserCredentials.h"

UserCredentials *newUserCredentials()
{

  UserCredentials *credentials = (UserCredentials *)malloc(sizeof(UserCredentials));
  credentials->username = NULL;
  credentials->password = NULL;

  return credentials;
}

UserCredentials *createFullUserCredentials(char *username, char *password, char *colorType)
{
  // create space for a new struct
  UserCredentials *credentials = (UserCredentials *)malloc(sizeof(UserCredentials));
  credentials->username = (char *)malloc((sizeof(char)*strlen(username))+1);
  credentials->password = (char *)malloc((sizeof(char)*strlen(password))+1);
  // credentials->colorType = (char *)malloc((sizeof(char)*strlen(colorType))+1);

  //copy of the data
  strcpy(credentials->username, username);
  strcpy(credentials->password, password);
  strcpy(credentials->colorType, colorType);

  return credentials;
}

void setUsername(UserCredentials *userCredentials, char *username)
{
  //malloc space for the username on struct
  userCredentials->username = (char *)malloc((sizeof(char)*strlen(username))+1);

  //copy the data
  strcpy(userCredentials->username, username);
}


void destroyUserCredentials(UserCredentials **userCredentials)
{
  UserCredentials *credentials = *(userCredentials);
  // free the credentials
  free(credentials->username);
  free(credentials->password);
  
  // free the struct
  free(credentials);

  //set to NULL
  *userCredentials = NULL;
}
