#ifndef PASSWORDS_H
#define PASSWORDS_H

#include <stdbool.h>

typedef unsigned char* EncryptedPassword;

EncryptedPassword newEncryptedPassword(char* text);
bool checkCorrectPasword(EncryptedPassword password, char* text);

#endif