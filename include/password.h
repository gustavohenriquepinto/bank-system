#ifndef PASSWORDS_H
#define PASSWORDS_H

#include "utils.h"

typedef unsigned char* EncryptedPassword;

void passwordInitialize(EncryptedPassword* password, char* text);
bool passwordIsCorrect(EncryptedPassword password, char* text);

#endif