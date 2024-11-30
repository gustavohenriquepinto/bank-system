#include "../include/transactionList.h"

void initList(LIST_Transaction* list) {
  list->start = NULL;
  list->size = 0;
}
void insertList(LIST_Transaction* list, Transaction* element) {
  ELEMENT* new = (ELEMENT*)malloc(sizeof(ELEMENT));
  new->reg = element;
  new->prox = NULL;
  ELEMENT* end = list->start;
}
void freeList(LIST_Transaction* list);