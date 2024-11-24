#ifndef USER_H
#define USER_H

#include "account.h"
#include "passwords.h"

typedef struct {
  char* name;
  Account account;
  EncryptedPassword password;
} User;

#endif
