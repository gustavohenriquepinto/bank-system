#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "date.h"
#include "user.h"
#include "utils.h"

int Method

typedef struct {
  User origin;
  User destiny;
  PAYMENT_METHOD method;
  Money value;
  Date date;
} Transaction;

ErrorController transactionDepositAccount(Account* account, Money value);
ErrorController transactionWithdrwawAccount(Account* account, Money value);
ErrorController transactionPayBill(Account* account, Money value);
ErrorController transactionPix(Account* from, Account* to, Money value);
ErrorController transactionTED(Account* from, Account* to, Money value);


#endif