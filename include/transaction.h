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

void transactionMenu();

#endif