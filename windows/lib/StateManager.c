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