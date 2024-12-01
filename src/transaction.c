#include "../include/transaction.h"

ErrorController transactionMenu(Account* account) {
  PAYMENT_METHOD method;

  utilsClearTerminal();
  accountPrint(account);

  puts("O que você quer fazer?");
  puts("0. Voltar");
  puts("1. Transferência via PIX");
  puts("2. Transferência via TED");
  puts("3. Pagamento de Boleto");

  scanf("%d", &method);

  switch (method) {
    case 0:
      return NO_ERROR;
    case 1:
      return transactionPix(account);
    case 2:
    case 3:
  }

  return INVALID_ACTION_ERROR;
}

ErrorController transactionDepositAccount(Account* account, Money value) {
  return accountIncreaseBalance(account, value);
}

ErrorController transactionWithdrwawAccount(Account* account, Money value) {
  return accountDecreaseBalance(account, value);
}

ErrorController transactionPayBill(Account* account, Money value) {
  // if (accountDecreaseBalance(account, value) == INSUFICCIENT_MONEY_ERROR)
  //   return INSUFICCIENT_MONEY_ERROR;
  // Agendado para dois dias
  return NO_ERROR;
}

ErrorController transactionNow(Account* from, Account* to, Money value) {
  if (accountDecreaseBalance(from, value) == NO_ERROR) {
    if (accountIncreaseBalance(to, value) != NO_ERROR) {
      accountIncreaseBalance(from, value);
      return MONEY_LIMIT_ERROR;
    } else
      return NO_ERROR;
  }
  return INSUFICCIENT_MONEY_ERROR;
}

ErrorController transactionPix(Account* origin) {
  int account_number;
  printf("Número da conta: ");
  scanf("%d", &account_number);

  Account destiny;
  databaseGetAccountByNumber(account_number, &destiny);

  double deposit = 0.0;

  printf("Deseja transferir qual valor?");
  scanf("%lf", &deposit);

  Money value = (Money)(deposit * 100);
  return transactionNow(origin, &destiny, value);
}

ErrorController transactionTED(Account* from, Account* to, Money value) {
  // if (accountDecreaseBalance(from, value) == INSUFICCIENT_MONEY_ERROR)
  //   return INSUFICCIENT_MONEY_ERROR;
  // Agendada para dois dias
  return NO_ERROR;
}

char* payment(PAYMENT_METHOD method) {
  switch (method) {
    case PIX:
      return "PIX";
    case TED:
      return "TED";
    case BILL:
      return "Boleto";
    default:
      return "Desconhecido";
  }
}

char* transactionText(Transaction* transaction) {
  char result[STRING_MAX];
  sprintf(result, "%s : %s -> $%d", dateToText(transaction->date),
          payment(transaction->method), transaction->value);
  return result;
}
