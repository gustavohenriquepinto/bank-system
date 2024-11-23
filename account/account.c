#include "account.h"

void initialize_account(Account* account) {
  account->balance = NO_MONEY;
}

int increase_account_balance(Account* account, double value) {
  if(account_would_pass_limit(account, value))
    return MONEY_LIMIT_ERROR;
  account->balance += value;
}

int decrease_account_balance(Account* account, double value) {
  if(!account_has_sufficient_money(account, value))
    return INSUFICCIENT_MONEY_ERROR;
  account->balance -= value;
}

bool account_has_sufficient_money(Account* account, double value) {
  return account->balance >= value;
}

bool account_would_pass_limit(Account* account, double value) {
  const double sum = account->balance + value;
  return sum <= account->balance || sum <= value; // Verifica se houve overflow
}