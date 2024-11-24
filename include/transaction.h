#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "./date.h"
#include "./user.h"
#include "./utils.h"

typedef struct {
  User origin;
  User destiny;
  Money value;
  Date date;
} Transaction;

#endif