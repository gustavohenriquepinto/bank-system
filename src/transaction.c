#include "../include/transaction.h"

#include "../include/database.h"
#include "../include/date.h"

#define TED_TAX (Money)1000

void transactionMenu() {
  Transaction transaction;
  ErrorController err;
  int account_number;
  double transferValue = 0.0;

  transaction.date = now();
  transaction.origin = *userGet();

  accountPrint(&transaction.origin.account);
  puts("O que voce quer fazer?");
  puts("0. Voltar");
  puts("1. Transferencia via PIX");
  puts("2. Transferencia via TED");
  puts("3. Pagamento de Boleto");

  scanf("%d", &transaction.method);
  if (transaction.method == 0) return error(NO_ERROR, MAIN_MENU);
  if (transaction.method < 1 || transaction.method > 3)
    return error(INVALID_ACTION_ERROR, TRANSACTION_MENU);

  if (transaction.method == 3)
    account_number = BANK_ACCOUNT;
  else {
    utilsClearTerminal();
    puts("Numero da conta: ");
    scanf("%d", &account_number);
    if (account_number == transaction.origin.account.number)
      return error(ENTER_ANOTHER_ACCOUNT_NUMBER, TRANSACTION_MENU);
  }

  err = databaseGetUserByAccountNumber(account_number, &transaction.destiny);
  if (err != NO_ERROR) return error(err, TRANSACTION_MENU);

  accountPrint(&transaction.origin.account);
  puts("Deseja transferir qual valor?");
  scanf("%lf", &transferValue);

  Money value = (Money)(transferValue * 100);
  if (accountDoesntHasSufficientMoney(&transaction.origin.account, value))
    return error(INSUFICCIENT_MONEY_ERROR, TRANSACTION_MENU);

  accountDecreaseBalance(&transaction.origin.account, value);
  accountIncreaseBalance(&transaction.destiny.account, value);

  databaseUpdateUser(&transaction.origin);
  databaseUpdateUser(&transaction.destiny);

  transaction.value = value;
  databaseInsertTransaction(&transaction);

  accountPrint(&transaction.origin.account);
  puts("Transaçao finalizada");
  error(NO_ERROR, MAIN_MENU);
}

ErrorController transactionDeposit(User* user, Money value) {
  ErrorController err;
  Transaction transaction;
  transaction.date = now();
  transaction.destiny = *user;
  transaction.value = value;
  transaction.method = DEPOSIT;

  err = databaseGetUserByAccountNumber(BANK_ACCOUNT, &transaction.origin);
  if (err != NO_ERROR) return err;

  err = accountIncreaseBalance(&(user->account), value);
  if (err != NO_ERROR) return err;

  err = databaseInsertTransaction(&transaction);
  if (err != NO_ERROR) return err;

  err = databaseUpdateUser(user);
  if (err != NO_ERROR) return err;

  return NO_ERROR;
}

ErrorController transactionWithdrwaw(User* user, Money value) {
  ErrorController err;
  Transaction transaction;
  transaction.date = now();
  transaction.origin = *user;
  transaction.value = value;
  transaction.method = WITHDRAWAL;

  err = databaseGetUserByAccountNumber(BANK_ACCOUNT, &transaction.destiny);
  if (err != NO_ERROR) return err;

  err = accountDecreaseBalance(&(user->account), value);
  if (err != NO_ERROR) return err;

  err = databaseInsertTransaction(&transaction);
  if (err != NO_ERROR) return err;

  err = databaseUpdateUser(user);
  if (err != NO_ERROR) return err;

  return NO_ERROR;
}
