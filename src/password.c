#include "../include/password.h"

#include <stdlib.h>
#include <string.h>

#define KEY 10

void passwordEncrypted(char* password, char* ciphered) {
  int i;

  for (i = 0; i < strlen(password); i++) {
    ciphered[i] = (((password[i] - 20) + KEY) % 107) + 20;
  }

  ciphered[i] = '\0';
}

bool passwordIsCorrect(char* inputPassword, char* password) {
  char encryptedInput[STRING_MAX];
  passwordEncrypted(inputPassword, encryptedInput);
  return utilsCompareIfIsSameString(password, encryptedInput);
}