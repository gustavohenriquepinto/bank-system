#ifndef PASSWORDS_H
#define PASSWORDS_H

#include "utils.h"

typedef unsigned char* EncryptedPassword;

void initializeEncryptedPassword(EncryptedPassword* password, char* text);
bool checkCorrectPassword(EncryptedPassword password, char* text);

#endif