// #include "../include/transactionList.h"

// void initList(LIST_Transaction* list) {
//   list->start = NULL;
//   list->size = 0;
// }
// void pushBackList(LIST_Transaction* list, Transaction* element) {
//   ELEMENT* new = (ELEMENT*)malloc(sizeof(ELEMENT));
//   new->reg = *element;
//   new->next = NULL;
//   if (list->start == NULL) {
//     list->start = new;
//     list->size++;
//     return;
//   }
//   ELEMENT* end = list->start;
//   while (end->next != NULL) {
//     end = end->next;
//   }
//   end->next = new;
//   list->size++;
// }
// void eraseList(LIST_Transaction* list, int pos) {
//   if (pos < 0 || pos >= list->size) return;
//   int i;
//   ELEMENT* p;
//   ELEMENT* erase;
//   if (pos == 0) {
//     erase = list->start;
//     list->start = erase->next;
//   } else {
//     p = list->start;
//     for (i = 0; i < pos - 1; i++) p = p->next;
//     erase = p->next;
//     p->next = erase->next;
//   }
//   free(erase);
//   list->size--;
// }

// PONT getFromList(LIST_Transaction* list, int pos){
//   if(pos<0||pos>=list->size) return NULL;
//   PONT end = list->start;
//   for(int i = 0; i<pos; i++) end = end->next;
//   return end;
// }

// void freeList(LIST_Transaction* list) {
//   ELEMENT* end = list->start;
//   while (end != NULL) {
//     ELEMENT* erase = end;
//     end = end->next;
//     free(erase);
//   }
//   free(list);
// }

// bool compareTransaction(Transaction a, Transaction b, SortMode mode){
//   switch (mode){
//   case DATE_ASCENDING_SORT:
//     return a.date > b.date;
//   case DATE_DESCENDING_SORT:
//     return a.date < b.date;
//   case VALUE_ASCENDING_SORT:
//     return a.value > b.value;
//   case VALUE_DESCENDING_SORT:
//     return a.value < b.value;
//   default:
//     return false;
//   }
// }

// void sortList(LIST_Transaction* list, SortMode mode){
//   for(int i = list->size-1; i>0; i--){
//     PONT jpont = list->start;
//     for(int j = 0; j<i; j++){
//       if(compareTransaction(jpont->reg, jpont->next->reg, mode)){
//         PONT aux = jpont->next->next;
//         jpont->next->next = jpont;
//         jpont->next = aux;
//         if(j==0) list->start = aux;
//       } else jpont = jpont->next;
//     }
//   }
// }
