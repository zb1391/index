#include "../headers/DataPackager.h"


int numCharsRequired(UserCredentials *credentials)
{
  char *username, *password, *colorType;

  username = credentials->username;
  password = credentials->password;
  colorType = credentials->colorType;
  
  //33 is the number of chars in the keys + \n's + null terminator
  return 33 + strlen(username) + strlen(password) + strlen(colorType);
}


char *packageUserCredentials(UserCredentials *credentials)
{
  char *packaged;
  int numChars;
  
  //get the number of chars required
  numChars = numCharsRequired(credentials);

  //create the string
  packaged = (char *)malloc(sizeof(char)*numChars);
  sprintf(packaged,
  	      "username:%s\npassword:%s\ncolor_type:%s\n",
  	      credentials->username,
  	      credentials->password,
  	      credentials->colorType);
  return packaged;

}
