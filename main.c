#include "include/database.h"
#include "include/user.h"
#include "include/utils.h"

ErrorController main(void) {
  databaseInitialize();
  setlocale(LC_ALL, "Portuguese");
  userLogin();

  return NO_ERROR;
}

// gcc main.c -o main src/*.c -Wall