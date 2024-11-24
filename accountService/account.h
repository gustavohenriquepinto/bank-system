#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdbool.h>

#define INSUFICCIENT_MONEY_ERROR -1
#define MONEY_LIMIT_ERROR -2

#define NO_MONEY 0
#define MONEY_LIMIT 1.7976931348623157 * pow(10, 308)

typedef struct {
  double balance;
} Account;

void initialize_account(Account* account);
int increase_account_balance(Account* account, double value);
int decrease_account_balance(Account* account, double value);
bool account_has_sufficient_money(Account* account, double value);


#endif