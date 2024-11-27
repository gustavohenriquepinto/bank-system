#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "utils.h"

#define NO_MONEY 0
#define MONEY_LIMIT 9223372036854775807

typedef struct {
  Money balance;
} Account;

void initializeAccount(Account* account);
ErrorController increaseAccountBalance(Account* account, Money value);
ErrorController decreaseAccountBalance(Account* account, Money value);

#endif