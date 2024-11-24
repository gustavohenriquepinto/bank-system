#include "include/transactions.h"

#include <stdio.h>

void printTransaction(Transaction* transaction) {
  printf("%s realizou uma transferência de %d para %s\n",
         transaction->origin.name, transaction->value,
         transaction->destiny.name);
}

void printHistory(SortMode sort);
