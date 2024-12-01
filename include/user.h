#ifndef USER_H
#define USER_H

// vou testar agora

#include "account.h"
#include "password.h"
#include "utils.h"

typedef struct {
  char name[STRING_MAX];
  char email[STRING_MAX];
  char password[STRING_MAX];
  Account account;
} User;

User* userGet();

void userLogin();
void userInitialize(User*);
void userSignIn(User* user);
void userSignUp(User* user);
void userGetString(char* message, char* destiny);

#endif
