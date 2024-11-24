#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "date.h"
#include "user.h"

#define DATE_ASCENDING_SORT 0
#define DATE_DESCENDING_SORT 1
#define VALUE_ASCENDING_SORT 2
#define VALUE_DESCENDING_SORT 3

typedef char SortMode;

typedef struct {
  User origin;
  User destiny;
  Money value;
  Date date;
} Transaction;

// void printTransaction(Transaction* transaction);
// void printHistory(SortMode sort);

#endif