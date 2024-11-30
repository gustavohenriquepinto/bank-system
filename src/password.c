#include "../include/password.h"

#include <stdlib.h>
#include <string.h>

#define KEY 10

void passwordEncrypted(EncryptedPassword text, char* ciphered) {
  int i;
  for (i = 0; i < strlen(ciphered); i++)
    ciphered[i] = (((text[i] - 20) + KEY) % 107) + 20;
  ciphered[i] = '\0';
}

bool passwordIsCorrect(EncryptedPassword password, char* inputPassword) {
  char encryptedInput[STRING_MAX];
  passwordEncrypted(inputPassword, encryptedInput);
  return utilsCompareIfIsSameString(password, encryptedInput);
}