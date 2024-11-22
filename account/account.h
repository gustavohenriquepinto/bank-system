#ifndef ACCOUNT.H
#define ACCOUNT.H

#include <stdbool.h>

#define INSUFICCIENT_MONEY_ERROR -1
#define NO_MONEY 0

typedef struct {
  double balance;
} Account;

void initialize_account(Account* account);
int increase_account_balance(Account* account, double value);
int decrease_account_balance(Account* account, double value);
bool account_has_sufficient_money(Account* account, double value);


#endif