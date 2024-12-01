#ifndef USER_H
#define USER_H

#include "account.h"
#include "password.h"
#include "utils.h"

typedef struct {
  char name[STRING_MAX];
  char email[STRING_MAX];
  char password[STRING_MAX];
  Account account;
} User;

void userLogin();
void userInitialize(User*);

User* userGet();
ErrorController userSignIn(User* user);
ErrorController userSignUp(User* user);
void userGetString(char* message, char* destiny);

#endif
