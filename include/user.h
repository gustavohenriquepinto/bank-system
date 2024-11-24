#ifndef USER_H
#define USER_H

#include "account/account.h"

typedef struct {
  char* name;
  Account checking_acount;
  Account saving_account;
} User;

#endif

