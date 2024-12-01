#include "../include/account.h"

#include "../include/database.h"
#include "../include/utils.h"

void initializeAccount(Account* account) {
  account->number = databaseGetAmountOfUsersRegisters() + 1;
  account->balance = 0;
}

void accountPrint(Account* account) {
  utilsClearTerminal();
  printf("Conta: %d\n", account->number);
  accountPrintMoney(account->balance);
}

void accountPrintMoney(Money money) {
  printf("Saldo: ");
  printf("%.2f", money / 100.0);
  puts("");
}

Money accountGetBalance(Account* account) { return account->balance; }

ErrorController accountDepositMenu(Account* account) {
  ErrorController error;
  double deposit = 0.0;
  Money value;

  utilsClearTerminal();
  accountPrint(account);
  printf("Deseja depositar qual valor?");
  scanf("%lf", &deposit);

  value = (Money)(deposit * 100);
  error = accountIncreaseBalance(account, value);

  utilsClearTerminal();
  accountPrint(account);
  puts("Deposito realizado com sucesso");
  system("pause");
  return error;
}

ErrorController accountPrintBalance(Account* account) {
  int x;
  utilsClearTerminal();
  accountPrintMoney(accountGetBalance(account));
  scanf("%d", &x);
  return NO_ERROR;
}

ErrorController accountWithdrawalMenu(Account* account) {
  double deposit = 0.0;
  Money value;

  utilsClearTerminal();
  accountPrint(account);
  printf("Deseja sacar qual valor?");
  scanf("%lf", &deposit);

  value = (Money)(deposit * 100);

  if (accountDoesntHasSufficientMoney(account, value)) {
    error(INSUFICCIENT_MONEY_ERROR);
    return INSUFICCIENT_MONEY_ERROR;
  }

  transactionWithdrwawAccount(account, value);
  utilsClearTerminal();
  accountPrint(account);
  puts("Saque realizado com sucesso");
  system("pause");
  return NO_ERROR;
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
  databaseUpdateAccount(account, account->balance);
  return NO_ERROR;
}

ErrorController accountDecreaseBalance(Account* account, Money value) {
  if (accountDoesntHasSufficientMoney(account, value))
    return INSUFICCIENT_MONEY_ERROR;
  account->balance -= value;
  databaseUpdateAccount(account, account->balance);
  return NO_ERROR;
}