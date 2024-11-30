#include "../include/database.h"

FILE* user_list;
int user_size;

void databaseInitialize() {
  user_list = fopen("users.data", "a");
  fseek(user_list, SEEK_END, 0);
  user_size = ftell(user_list) / sizeof(User);
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
    fread(&user, sizeof(User), 1, user_list);
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
}

// ErrorController databaseRemoveUser(User* user) {
//   for (int i = 0; i < MAX_USERS; i++)
//     if (utilsCompareIfIsSameString(user_list[i].email, user->email)) {
//       // Implementar: remover usuário da lista e trazer todos para frente
//       user_size--;
//       break;
//     }
//   return NO_ERROR;
// }

//////////////////////////////////////////////////////////////////////////
