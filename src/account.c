#include "include/account.h"

bool accountDoesntHasSufficientMoney(Account* account, Money value) {
  return account->balance >= value;
}

bool accountWouldPassLimit(Account* account, Money value) {
  const Money sum = account->balance + value;
  return sum <= account->balance || sum <= value;  // Verifica se houve overflow
}

void initializeAccount(Account* account) { account->balance = NO_MONEY; }

int increaseAccountBalance(Account* account, Money value) {
  if (accountWouldPassLimit(account, value)) return MONEY_LIMIT_ERROR;
  account->balance += value;
}

int decreaseAccountBalance(Account* account, Money value) {
  if (accountDoesntHasSufficientMoney(account, value))
    return INSUFICCIENT_MONEY_ERROR;
  account->balance -= value;
}