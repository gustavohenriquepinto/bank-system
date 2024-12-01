#include "../include/transaction.h"

#define TED_TAX (Money)1000

void transactionMenu() {
  Transaction transaction;
  User destiny;
  ErrorController err;
  int account_number;
  double transferValue = 0.0;

  transaction.origin = *userGet();

  accountPrint(&transaction.origin.account);
  puts("O que você quer fazer?");
  puts("0. Voltar");
  puts("1. Transferência via PIX");
  puts("2. Transferência via TED");
  puts("3. Pagamento de Boleto");

  scanf("%d", &transaction.method);
  if (transaction.method == 0) return error(NO_ERROR, MAIN_MENU);
  if (transaction.method < 1 || transaction.method > 3)
    return error(INVALID_ACTION_ERROR, TRANSACTION_MENU);

  printf("Número da conta: ");
  scanf("%d", &account_number);

  err = databaseGetUserByAccountNumber(account_number, &transaction.destiny);
  if (err != NO_ERROR) return error(err, TRANSACTION_MENU);

  printf("Deseja transferir qual valor?");
  scanf("%lf", &transferValue);

  Money value = (Money)(transferValue * 100);
  if (accountDoesntHasSufficientMoney(&transaction.origin.account, value))
    return error(INSUFICCIENT_MONEY_ERROR, TRANSACTION_MENU);

  accountDecreaseBalance(&transaction.origin.account, value);
  accountIncreaseBalance(&transaction.destiny.account, value);
  databaseUpdateUser(userGet());
  databaseUpdateUser(&transaction.destiny);

  databaseInsertTransaction(transaction);
}