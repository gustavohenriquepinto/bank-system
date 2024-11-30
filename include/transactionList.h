#include "transaction.h"

typedef struct aux {
  Transaction reg;
  struct aux* prox;
} ELEMENT;

typedef ELEMENT* PONT;

typedef struct {
  PONT start;
  int size;
} LIST_Transaction;

void initList(LIST_Transaction* list);
void insertList(LIST_Transaction* list, Transaction* element);
void freeList(LIST_Transaction* list);