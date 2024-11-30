#ifndef PASSWORDS_H
#define PASSWORDS_H

#include "utils.h"

typedef char* EncryptedPassword;

void passwordEncrypted(EncryptedPassword, char*);
bool passwordIsCorrect(EncryptedPassword, char*);

#endif