#include <locale.h>
#include <stdio.h>

#include "include/user.h"

int menu() {
  utilsClearTerminal();
  puts("O que você deseja?");
  return 0;
}

int main(void) {
  utilsClearTerminal();
  setlocale(LC_ALL, "Portuguese");

  if (userLogin()) menu();
  puts("ok");

  return 0;
}

// gcc main.c -o main src/*.c -Wall -Iinclude -lcrypto -lm