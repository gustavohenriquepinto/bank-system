#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "database.h"
#include "date.h"
#include "user.h"
#include "utils.h"

typedef struct {
  User origin;
  User destiny;
  PAYMENT_METHOD method;
  Money value;
  Date date;
} Transaction;

ErrorController transactionMenu(Account* account);
ErrorController transactionDepositAccount(Account* account, Money value);
ErrorController transactionWithdrwawAccount(Account* account, Money value);
ErrorController transactionPayBill(Account* account, Money value);
ErrorController transactionPix(Account* origin);
ErrorController transactionTED(Account* from, Account* to, Money value);

char* transactionText(Transaction* transaction);

#endif