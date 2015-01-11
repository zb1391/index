/*
 * DataPackager.h
 *
 */

#include <yaml.h>
#include <stdio.h>
#include "UserCredentials.h"

#ifndef DataPackager_H
#define DataPackager_H

// get the number of charrs required to build the YAML string
 int numCharsRequired(UserCredentials *credentials);

// convert the UserCredentials into a YAML string
char *packageUserCredentials(UserCredentials *UserCredentials);


#endif