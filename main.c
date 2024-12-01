#include "include/database.h"
#include "include/transaction.h"
#include "include/user.h"
#include "include/utils.h"

ErrorController menu(User* user) {
  char action = -1;

  utilsClearTerminal();
  puts("O que você deseja?");
  puts("0. Sair");
  puts("1. Consultar saldo");
  puts("2. Realizar um depósito");
  puts("3. Realizar um saque");
  puts("4. Realizar uma transferência");
  puts("5. Gerar um relatório");

  scanf("%c", &action);
  scanf("%*c");

  if (action < 0) return menu(user);
  if (action == 0) return NO_ERROR;
  if (action == 1) accountPrintMoney(accountGetBalance(&(user->account)));
  if (action == 2) accountDepositMenu(&(user->account));
  if (action == 3) accountWithdrawalMenu(&(user->account));
  if (action == 4) transactionMenu(&(user->account));

  puts("Aperte enter para retornar ao menu");
  scanf("%c", &action);
  menu(user);

  return 0;
}

ErrorController main(void) {
  int action = -1;
  ErrorController valid = NO_ERROR;
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
    if (action == 1) valid = userSignIn(&user);
    if (action == 2) valid = userSignUp(&user);
  }

  if (valid != NO_ERROR) return error(valid);
  if (action) menu(&user);

  return NO_ERROR;
}

// gcc main.c -o main src/*.c -Wall -Iinclude