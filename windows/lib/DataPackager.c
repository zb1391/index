#include "../headers/DataPackager.h"


int numCharsRequired(UserCredentials *credentials)
{
  char *username, *password, *colorType;

  username = credentials->username;
  password = credentials->password;
  colorType = credentials->colorType;
  
  /*where did 41 come from:
   * we are packaging as "{:username=>USERNAME,:password=>PASSWORD,:color_type=>COLOR}"
   * {} -- 2
   * 2 commas, 3 colons, 3 hashrockets (=>) -- 11
   * username -- 8
   * password -- 8
   * color_type -- 10
   * newline char (\n) --1
   * terminating char (\0) -- 1
   * TOTAL = 41
   */ 
  return 41 + strlen(username) + strlen(password) + strlen(colorType);
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
  	      "{:username=>%s,:password=>%s,:color_type=>%s}\n",
  	      credentials->username,
  	      credentials->password,
  	      credentials->colorType);
  return packaged;

}
