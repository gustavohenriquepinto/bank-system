#include <locale.h>
#include <stdio.h>

#include "include/user.h"

int menu() {
  int action = -1;
  utilsClearTerminal();
  puts("O que você deseja?");
  puts("1. Consultar saldo");
  puts("2. Realizar um depósito");
  puts("3. Realizar um saques");
  puts("4. ");
  return 0;
}

int main(void) {
  int action = -1;

  setlocale(LC_ALL, "Portuguese");

  while (action < 0 || action > 2) {
    utilsClearTerminal();
    puts("Bem vindo ao Finance Bank, como deseja prosseguir?");
    puts("1. Entrar na sua conta");
    puts("2. Criar uma conta");
    scanf("%d", &action);

    if (action == 1) return userSignIn();
    if (action == 2) return userSignUp();
  }

  return 0;
}

// gcc main.c -o main src/*.c -Wall -Iinclude -lcrypto -lm