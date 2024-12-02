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

PONT getFromList(LIST_Transaction* list, int pos) {
  if (pos < 0 || pos >= list->size) return NULL;
  PONT end = list->start;
  for (int i = 0; i < pos; i++) end = end->next;
  return end;
}

void freeList(LIST_Transaction* list) {
  ELEMENT* end = list->start;
  while (end != NULL) {
    ELEMENT* erase = end;
    end = end->next;
    free(erase);
  }
  initList(list);
}

bool compareTransaction(Transaction a, Transaction b, SortMode mode) {
  switch (mode) {
    case DATE_ASCENDING_SORT:
      return a.date > b.date;
    case DATE_DESCENDING_SORT:
      return a.date < b.date;
    case VALUE_ASCENDING_SORT:
      return a.value > b.value;
    case VALUE_DESCENDING_SORT:
      return a.value < b.value;
    default:
      return false;
  }
}

void sortList(LIST_Transaction* list, SortMode mode) {
  for (int i = list->size - 1; i > 0; i--) {
    PONT jpont = list->start, previous;
    for (int j = 0; j < i; j++) {
      if (compareTransaction(jpont->reg, jpont->next->reg, mode)) {
        PONT aux1 = jpont->next->next, aux2 = jpont->next;
        jpont->next->next = jpont;
        jpont->next = aux1;
        if (j == 0)
          list->start = aux2;
        else
          previous->next = aux2;
      } else
        jpont = jpont->next;
      if (j > 0)
        previous = previous->next;
      else
        previous = list->start;
    }
  }
}

void filterList(LIST_Transaction* list, PAYMENT_METHOD method) {
  if (method <= 0 || method > 5) return;
  PONT end = list->start, previous;
  for (int i = 0; i < list->size; i++) {
    while (end != NULL && end->reg.method != method) {
      eraseList(list, i);
      if (i == 0)
        end = list->start;
      else
        end = previous->next;
    }
    if (end == NULL) break;
    end = end->next;
    if (i == 0)
      previous = list->start;
    else
      previous = previous->next;
  }
}

void printList(LIST_Transaction* list) {
  PONT end = list->start;
  while (end != NULL) {
    printf("Data: %s\n", dateText(end->reg.date));
    printf("Valor: R$ %.2f\n", end->reg.value / 100.0);
    printf("De %s para %s\n\n", end->reg.origin.name, end->reg.destiny.name);
    end = end->next;
  }
}
