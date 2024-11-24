#include "include/database.h"

typedef struct {
  User user;
  UserElement* next;
} UserElement;

typedef struct {
  UserElement *first, *last;
  int size;
} UserList;

UserList user_list = (UserList){NULL, NULL, 0};

bool databaseHasUser(char* email) {
  UserElement* user_element = user_list.first;
  do {
    if (utilsCompareIfIsSameString(user_element->user.email, email)) {
      free(user_element);
      return true;
    }
  } while (user_element->next != NULL);

  free(user_element);
  return false;
}

ErrorController databaseInsertUser(User* user) {
  UserElement* user_element = malloc(sizeof(UserElement));
  user_element->user = *user;
  user_element->next = NULL;

  if (user_list.first == NULL)
    user_list.first = user_element;
  else
    user_list.last->next = user_element;

  user_list.last = user_element;
  user_list.size++;
  free(user_element);
  return NO_ERROR;
}
