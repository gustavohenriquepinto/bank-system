#ifndef PASSWORDS_H
#define PASSWORDS_H

#include "utils.h"

void passwordEncrypted(char* input, char* password);
bool passwordIsCorrect(char* input, char* password);

#endif