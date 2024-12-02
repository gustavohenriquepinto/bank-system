#ifndef USER_H
#define USER_H

#include "account.h"
#include "password.h"
#include "utils.h"

#define BANK_ACCOUNT 0

typedef struct {
  char name[STRING_MAX];
  char email[STRING_MAX];
  char password[STRING_MAX];
  Account account;
} User;

User* userGet();

void userLogin();
void userInitialize(User*);
void userSignIn();
void userSignUp();
void userGetString(char* message, char* destiny);

#endif
