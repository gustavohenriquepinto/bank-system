#include "../include/transactionList.h"

void initList(LIST_Transaction* list) {
  list->start = NULL;
  list->size = 0;
}
void pushBackList(LIST_Transaction* list, Transaction* element) {
  ELEMENT* new = (ELEMENT*)malloc(sizeof(ELEMENT));
  new->reg = *element;
  new->next = NULL;
  if (list->start == NULL) {
    list->start = new;
    list->size++;
    return;
  }
  ELEMENT* end = list->start;
  while (end->next != NULL) {
    end = end->next;
  }
  end->next = new;
  list->size++;
}
void eraseList(LIST_Transaction* list, int pos) {
  if (pos < 0 || pos >= list->size) return;
  int i;
  ELEMENT* p;
  ELEMENT* erase;
  if (pos == 0) {
    erase = list->start;
    list->start = erase->next;
  } else {
    p = list->start;
    for (i = 0; i < pos - 1; i++) p = p->next;
    erase = p->next;
    p->next = erase->next;
  }
  free(erase);
  list->size--;
}

void freeList(LIST_Transaction* list) {
  ELEMENT* end = list->start;
  while (end != NULL) {
    ELEMENT* erase = end;
    end = end->next;
    free(erase);
  }
  free(list);
}