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

void accountDepositMenu() {
  User* user = userGet();
  ErrorController err;
  double deposit = 0.0;
  Money value;

  utilsClearTerminal();
  accountPrint(&(user->account));
  puts("Deseja depositar qual valor?");
  scanf("%lf", &deposit);

  value = (Money)(deposit * 100);
  err = transactionDeposit(user, value);
  if (err != NO_ERROR) return error(err, MAIN_MENU);

  accountPrint(&(user->account));
  puts("Deposito realizado com sucesso");
  error(NO_ERROR, MAIN_MENU);
}

void accountWithdrawalMenu() {
  User* user = userGet();
  ErrorController err;
  double deposit = 0.0;
  Money value;

  utilsClearTerminal();
  accountPrint(&(user->account));
  puts("Deseja sacar qual valor?");
  scanf("%lf", &deposit);

  value = (Money)(deposit * 100);
  err = transactionWithdrwaw(userGet(), value);
  if (err != NO_ERROR) return error(err, MAIN_MENU);

  accountPrint(&(user->account));
  puts("Saque realizado com sucesso");
  error(NO_ERROR, MAIN_MENU);
}

bool accountDoesntHasSufficientMoney(Account* account, Money value) {
  return account->balance <= value;
}

ErrorController accountIncreaseBalance(Account* account, Money value) {
  if (value < 0) return NEGATIVE_NUMBER_ERROR;
  account->balance += value;
  return NO_ERROR;
}

ErrorController accountDecreaseBalance(Account* account, Money value) {
  if (accountDoesntHasSufficientMoney(account, value))
    return INSUFICCIENT_MONEY_ERROR;
  account->balance -= value;
  return NO_ERROR;
}