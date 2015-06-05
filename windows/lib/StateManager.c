#include "../headers/StateManager.h"

char *getQuestion(stateType state)
{
  char *question = NULL;
  switch(state){
    case GetUsername:
      question = (char *)malloc(sizeof(char)*(strlen("Enter your username:")+1));
      sprintf(question,"%s", "Enter your username:");
      break;
  }
  return question;
}

void askQuestion(char **question)
{
  printf("%s\n",*(question));
  free(*(question));
  *(question) = NULL;
}

char *getResponse()
{
  int i,max;
  char c, *response;
    max = 20;
  response = (char *)malloc(max);

  i = 0;
  while(1)
  {
    c = getchar();

    /* stop reading if user enters c or enter */
    if(isspace(c) || c == EOF)
    {
      response[i] = '\0';
      break;
    }

    /* add char to response */
    response[i] = c;

    /* add more memory if buffer is full */
    if(i == max-1)
    {
      max += max;
      response = (char *)realloc(response,max);
    }

    i++;
  }

  return response;
}

char checkValidUsername(char *username){
  /* invalid is NULL or empty string*/
  char isValid = (username == NULL || strlen(username) == 0) ? 0 : 1;
  if(!isValid)
  {
    printf("Username can't be blank\n");
  }
  return isValid;
}
