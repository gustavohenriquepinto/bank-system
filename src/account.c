#include "include/account.h"

bool accountDoesntHasSufficientMoney(Account* account, long int value) {
  return account->balance >= value;
}

bool accountWouldPassLimit(Account* account, long int value) {
  const long int sum = account->balance + value;
  return sum <= account->balance || sum <= value;  // Verifica se houve overflow
}

void initializeAccount(Account* account) { account->balance = NO_MONEY; }

int increaseAccountBalance(Account* account, long int value) {
  if (accountWouldPassLimit(account, value)) return MONEY_LIMIT_ERROR;
  account->balance += value;
}

int decreaseAccountBalance(Account* account, long int value) {
  if (accountDoesntHasSufficientMoney(account, value))
    return INSUFICCIENT_MONEY_ERROR;
  account->balance -= value;
}