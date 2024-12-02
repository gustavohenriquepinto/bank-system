#ifndef TRANSACTION_L_H
#define TRANSACTION_L_H

#include "transaction.h"

typedef struct aux {
  Transaction reg;
  struct aux* next;
} ELEMENT;

typedef ELEMENT* PONT;

typedef struct {
  PONT start;
  int size;
} LIST_Transaction;

void initList(LIST_Transaction* list);
void pushBackList(LIST_Transaction* list, Transaction* element);
void eraseList(LIST_Transaction* list, int pos);
void freeList(LIST_Transaction* list);
void sortList(LIST_Transaction* list, SortMode mode);
void filterList(LIST_Transaction* list, PAYMENT_METHOD method);
void printList(LIST_Transaction* list);

#endif