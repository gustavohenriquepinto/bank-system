#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdbool.h>

#define INSUFICCIENT_MONEY_ERROR -1
#define MONEY_LIMIT_ERROR -2

#define NO_MONEY 0
#define MONEY_LIMIT 9223372036854775807

typedef struct {
  long int balance;
} Account;

bool accountDoesntHasSufficientMoney(Account* account, long int value);
bool accountWouldPassLimit(Account* account, long int value);

void initializeAccount(Account* account);
int increaseAccountBalance(Account* account, long int value);
int decreaseAccountBalance(Account* account, long int value);

#endif