#ifndef ACCOUNT.H
#define ACCOUNT.H

#include "../bank/account/account.h"

typedef struct {
  char* name;
  Account checking_acount;
  Account saving_account;
} User;

#endif

