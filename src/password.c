#include "../include/password.h"

#include <stdlib.h>
#include <string.h>

#define KEY 839420

void passwordEncrypted(char* input, char* password) {
  int i = 0;
  for (; input[i] != '\0'; i++) password[i] = ((input[i] + KEY) % 107) + 20;
  password[i] = '\0';
}

bool passwordIsCorrect(char* input, char* password) {
  char encryptedInput[STRING_MAX];
  passwordEncrypted(input, encryptedInput);
  return utilsCompareIfIsSameString(password, encryptedInput);
}