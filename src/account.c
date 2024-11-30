#include "../include/account.h"

#include "../include/database.h"
#include "../include/utils.h"

void initializeAccount(Account* account) {
  account->number = databaseGetAmountOfUsersRegisters() + 1;
  account->balance = 0;
}

void accountPrint(Account* account) {
  printf("Conta: %d\n", account->number);
  printf("Saldo: ");
  accountPrintMoney(account->number);
  puts("");
}

void accountPrintMoney(Money money) { printf("%2ld", money / 100); }

Money accountGetBalance(Account* account) { return account->balance; }

void accountDepositMenu(Account* account) {
  double deposit = 0.0;
  Money balance;

  utilsClearTerminal();
  accountPrint(account);
  printf("Deseja depositar qual valor?");
  scanf("%lf", &deposit);

  balance = (Money)(deposit * 100);
  transactionDepositAccount(account, balance);

  utilsClearTerminal();
  accountPrint(account);
  puts("Deposito realizado com sucesso");
}

void accountWithdrawalMenu(Account* account) {
  double deposit = 0.0;
  Money value;

  utilsClearTerminal();
  accountPrint(account);
  printf("Deseja sacar qual valor?");
  scanf("%lf", &deposit);

  value = (Money)(deposit * 100);

  if (accountDoesntHasSufficientMoney(account, value)) {
    error(INSUFICCIENT_MONEY_ERROR);
    return;
  }

  transactionWithdrwawAccount(account, value);
  utilsClearTerminal();
  accountPrint(account);
  puts("Saque realizado com sucesso");
}

bool accountDoesntHasSufficientMoney(Account* account, Money value) {
  return account->balance <= value;
}

bool accountWouldPassLimit(Account* account, Money value) {
  const Money sum = account->balance + value;
  return sum < account->balance || sum < value;  // Verifica se houve overflow
}

ErrorController accountIncreaseBalance(Account* account, Money value) {
  if (accountWouldPassLimit(account, value)) return MONEY_LIMIT_ERROR;
  account->balance += value;
  return NO_ERROR;
}

ErrorController accountDecreaseBalance(Account* account, Money value) {
  if (accountDoesntHasSufficientMoney(account, value))
    return INSUFICCIENT_MONEY_ERROR;
  account->balance -= value;
  return NO_ERROR;
}