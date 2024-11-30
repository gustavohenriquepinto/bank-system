#include "../include/database.h"

// sabe o que fazer?
// consegue implementar da mesma forma que fiz com usuarios para adicionar
// transações num arquivo binario? no caso, as transações nunca vao ser
// excluidas. unica diferença. seria só replicar a lógica do arquivo de usuários

// Consigo, mas seria todas as transações num só arquivo mesmo? Sem separar por
// usuário?
// Isso -Diego

FILE* user_list;
int user_size;

FILE* transaction_list;
int transaction_size;

void databaseInitialize() {
  user_list = fopen("users.data", "ab+");
  fseek(user_list, SEEK_END, 0);
  user_size = ftell(user_list) / sizeof(User);

  transaction_list = fopen("transactions.data", "ab+");
  fseek(transaction_list, SEEK_END, 0);
  transaction_size = ftell(transaction_list) / sizeof(Transaction);
}

bool databaseHasUser(char* email) {
  rewind(user_list);
  fseek(user_list, SEEK_SET, 0);
  while (!feof(user_list)) {
    User user;
    fread(&user, sizeof(User), 1, user_list);
    if (utilsCompareIfIsSameString(email, user.email)) return true;
  }
  return false;
}

ErrorController databaseGetUser(char* email, User* user) {
  rewind(user_list);
  fseek(user_list, SEEK_SET, 0);
  while (!feof(user_list)) {
    User user_temp;
    fread(&user_temp, sizeof(User), 1, user_list);
    if (utilsCompareIfIsSameString(email, user_temp.email)) {
      *user = user_temp;
      return NO_ERROR;
    }
  }
  return USER_DOENST_EXIST_ERROR;
}

int databaseGetAmountOfUsersRegisters() { return user_size; }

ErrorController databaseInsertUser(User* user) {
  rewind(user_list);
  fseek(user_list, SEEK_END, 0);
  fwrite(user, sizeof(User), 1, user_list);
  user_size++;
  return NO_ERROR;
}

ErrorController databaseRemoveUser(User* user) { return NO_ERROR; }

//////////////////////////////////////////////////////////////////////////

ErrorController databaseInsertTransaction(Transaction* transaction) {
  fseek(transaction_list, SEEK_END, 0);
  fwrite(transaction, sizeof(Transaction), 1, transaction_list);
  transaction_size++;
  return NO_ERROR;
}
