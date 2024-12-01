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

void accountDepositMenu(Account* account) {
  ErrorController err;
  double deposit = 0.0;
  Money value;

  utilsClearTerminal();
  accountPrint(account);
  puts("Deseja depositar qual valor?");
  scanf("%lf", &deposit);

  value = (Money)(deposit * 100);
  err = accountIncreaseBalance(account, value);
  if (err != NO_ERROR) return error(err, MAIN_MENU);

  accountPrint(account);
  puts("Deposito realizado com sucesso");
  error(NO_ERROR, MAIN_MENU);
}

void accountWithdrawalMenu(Account* account) {
  Transaction transaction;
  double deposit = 0.0;
  Money value;

  utilsClearTerminal();
  accountPrint(account);
  puts("Deseja sacar qual valor?");
  scanf("%lf", &deposit);

  //,precisamos pensar em um destinatario null

  value = (Money)(deposit * 100);
  transaction.origin = *userGet();
  transaction.value = value;

  if (accountDoesntHasSufficientMoney(account, value))
    return error(INSUFICCIENT_MONEY_ERROR, MAIN_MENU);

  transactionWithdrwawAccount(account, value);
  accountPrint(account);
  puts("Saque realizado com sucesso");
  error(NO_ERROR, MAIN_MENU);
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
  return databaseUpdateUser(userGet());
}

ErrorController accountDecreaseBalance(Account* account, Money value) {
  if (accountDoesntHasSufficientMoney(account, value))
    return INSUFICCIENT_MONEY_ERROR;
  account->balance -= value;
  return databaseUpdateUser(userGet());
}