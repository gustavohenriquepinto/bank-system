#ifndef PASSWORDS_H
#define PASSWORDS_H

#include <stdbool.h>

typedef unsigned char* EncryptedPassword;

void initializeEncryptedPassword(EncryptedPassword* password, char* text);
bool checkCorrectPasword(EncryptedPassword password, char* text);

#endif