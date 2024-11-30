#include "../include/transaction.h"

void transactionMenu(Account* account) {
  PAYMENT_METHOD method;

  utilsClearTerminal();
  accountPrint(account); 

  puts("Escolhar o metódo de pagamento:");
  scanf("%d", &method);
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

ErrorController transactionPix(Account* from, Account* to, Money value) {
  return transactionNow(to, from, value);
}

ErrorController transactionTED(Account* from, Account* to, Money value) {
  // if (accountDecreaseBalance(from, value) == INSUFICCIENT_MONEY_ERROR)
  //   return INSUFICCIENT_MONEY_ERROR;
  // Agendada para dois dias
}
