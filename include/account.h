#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdbool.h>

#define INSUFICCIENT_MONEY_ERROR -1
#define MONEY_LIMIT_ERROR -2

#define NO_MONEY 0
#define MONEY_LIMIT 9223372036854775807

typedef long int Money;

typedef struct {
  Money balance;
} Account;

// Privados não precisam ser ddeclarados no arquivo .h
// bool accountDoesntHasSufficientMoney(Account* account, Money value);
// bool accountWouldPassLimit(Account* account, Money value);

void initializeAccount(Account* account);
int increaseAccountBalance(Account* account, Money value);
int decreaseAccountBalance(Account* account, Money value);

#endif