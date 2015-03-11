#include "../headers/DataPackager.h"


int numCharsRequired(UserCredentials *credentials)
{
  char *username, *password, *colorType;

  username = credentials->username;
  password = credentials->password;
  colorType = credentials->colorType;
  
  /*where did 40 come from:
   * we are packaging as "{:username=>USERNAME,:password=>PASSWORD,:color_type=>COLOR}"
   * {} -- 2
   * 2 commas, 3 colons, 3 hashrockets (=>) -- 11
   * username -- 8
   * password -- 8
   * color_type -- 10
   * terminating char (\0) -- 1
   * TOTAL = 40
   */ 
  return 40 + strlen(username) + strlen(password) + strlen(colorType);
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
  	      "{:username=>%s,:password=>%s,:color_type=>%s}",
  	      credentials->username,
  	      credentials->password,
  	      credentials->colorType);
  return packaged;

}
