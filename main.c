#include <locale.h>
#include <stdio.h>

#include "include/user.h"

ErrorController menu(User* user) {
  int action = -1;

  utilsClearTerminal();
  puts("O que você deseja?");
  puts("0. Sair");
  puts("1. Consultar saldo");
  puts("2. Realizar um depósito");
  puts("3. Realizar um saque");
  puts("4. Realizar uma transferência");
  puts("5. Gerar um relatório");

  scanf("%d", &action);
  if (action < 0) return menu(user);
  if (action == 0) return main();
  if (action == 1) accountPrintMoney(accountGetBalance(&(user->account)));
  if (action == 2) accountDepositMenu(&(user->account));
  if (action == 3) accountWithdrawalMenu(&(user->account));
  if (action == 4) transactionMenu(&(user->account));

  puts('Aperte enter para retornar ao menu');
  scanf("%c");
  menu(user);

  return 0;
}

int main(void) {
  int action = -1;
  User user;

  databaseInitialize();
  setlocale(LC_ALL, "Portuguese");

  while (action < 0 || action > 2) {
    utilsClearTerminal();
    puts("Bem vindo ao Finance Bank, como deseja prosseguir?");
    puts("0. Encerrar programa");
    puts("1. Entrar na sua conta");
    puts("2. Criar uma conta");
    scanf("%d", &action);

    if (action == 0) break;
    if (action == 1) userSignIn(&user);
    if (action == 2) userSignUp(&user);
  }

  menu(&user);

  return 0;
}

// gcc main.c -o main.out src/*.c -Wall -Iinclude -lcrypto -lm