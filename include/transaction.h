#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "date.h"
#include "user.h"
typedef struct {
  User origin;
  User destiny;
  PAYMENT_METHOD method;
  Money value;
  Date date;
} Transaction;

void transactionMenu();
ErrorController transactionDeposit(User*, Money);
ErrorController transactionWithdrwaw(User*, Money);

#endif