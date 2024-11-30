#include "../include/database.h"

// typedef struct UserElement {
//   User user;
//   struct UserElement* next;
// };

// typedef struct UserElement UserElement;

// typedef struct {
//   UserElement *first, *last;
//   int size;
// } UserList;

// UserList user_list = (UserList){NULL, NULL, 0};

// bool databaseHasUser(char* email) {
//   UserElement* user_element = user_list.first;
//   do {
//     if (utilsCompareIfIsSameString(user_element->user.email, email)) {
//       free(user_element);
//       return true;
//     }
//   } while (user_element->next != NULL);

//   free(user_element);
//   return false;
// }

// ErrorController databaseInsertUser(User* user) {
//   UserElement* user_element = malloc(sizeof(UserElement));
//   user_element->user = *user;
//   user_element->next = NULL;

//   if (user_list.first == NULL)
//     user_list.first = user_element;
//   else
//     user_list.last->next = user_element;

//   user_list.last = user_element;
//   user_list.size++;
//   free(user_element);
//   return NO_ERROR;
// }

// ErrorController databaseRemoveUser(User* user) {
//   UserElement* user_element = user_list.first;
//   do {
//     if (utilsCompareIfIsSameString(user_element->user.email, user->email)) {
//       user_element->next = user_element->next->next;
//       user_list.size--;
//       free(user_element);
//       return NO_ERROR;
//     }
//   } while (user_element->next != NULL);

//   free(user_element);
//   return USER_DOENST_EXIST_ERROR;
// }

#define MAX_USERS 100
User user_list[MAX_USERS];
int size = 0;

bool databaseHasUser(char* email) {
  for (int i = 0; i < MAX_USERS; i++)
    if (utilsCompareIfIsSameString(user_list[i].email, email)) return true;
  return false;
}

ErrorController databaseInsertUser(User* user) {
  User* _user = &user_list[size];
  _user->name = user->name;
  _user->email = user->email;
  _user->password = user->password;
  _user->account = user->account;
  free(_user);
  size++;
  return NO_ERROR;
}

ErrorController databaseRemoveUser(User* user) {
  for (int i = 0; i < MAX_USERS; i++)
    if (utilsCompareIfIsSameString(user_list[i].email, user->email)) {
            size--;
    }

  return true;
  return false;
}