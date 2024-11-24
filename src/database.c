// #include "include/database.h"

// typedef struct {
//   User user;
//   UsersList* prox;
// } UsersList;

// UsersList users_list;

// bool databaseHasUser(char* email) {
//   UsersList aux = users_list;
//   while (aux.prox != NULL) {
//     if (utilsCompareIfIsSameString(email, users_list.user.email)) return
//     true; aux = aux.prox;
//   }
//   return false;
// }

// bool databaseInsertUser(User* user) {
//   UsersList aux;
//   aux.user = user;
//   aux.prox = NULL;
//   if (databaseHasUser(user->email)) return false;  // Criar um erro
//   while (aux.prox != NULL)
//     aux = aux.prox;

// }
