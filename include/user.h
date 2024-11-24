#ifndef USER_H
#define USER_H

#include "./account.h"
#include "./password.h"
#include "./utils.h"

typedef struct {
  char* name;
  char* email;
  Account account;
  EncryptedPassword password;
} User;

bool userSignUp();
bool userSignIn();
bool userLogin();

#endif
