#include "include/database.h"
#include "include/report.h"
#include "include/transaction.h"
#include "include/user.h"
#include "include/utils.h"

ErrorController menu(User* user) {
  int action = -1;
  // int x;

  utilsClearTerminal();
  puts("O que você deseja?");
  puts("0. Sair");
  puts("1. Consultar saldo");
  puts("2. Realizar um depósito");
  puts("3. Realizar um saque");
  puts("4. Realizar um pagamento");
  puts("5. Gerar um relatório");

  scanf("%d", &action);

  if (action == 0) return NO_ERROR;
  if (action == 1) accountPrintBalance(&(user->account));
  if (action == 2 && accountDepositMenu(&(user->account)) == MONEY_LIMIT_ERROR)
    return MONEY_LIMIT_ERROR;
  if (action == 3) accountWithdrawalMenu(&(user->account));
  if (action == 4) transactionMenu(&(user->account));
  if (action == 5) reportMenu();

  return menu(user);
}

ErrorController main(void) {
  int action = -1;
  ErrorController valid = NO_ERROR;
  User user;

  userInitialize(&user);

  databaseInitialize();
  setlocale(LC_ALL, "Portuguese");

  while (action < 0 || action > 2) {
    utilsClearTerminal();
    puts("Bem vindo ao Finance Bank, como deseja prosseguir?");
    puts("0. Encerrar programa");
    puts("1. Entrar na sua conta");
    puts("2. Criar uma conta");
    scanf("%d", &action);

    if (action == 0) return NO_ERROR;
    if (action == 1) valid = userSignIn(&user);
    if (action == 2) valid = userSignUp(&user);
  }

  if (valid != NO_ERROR) error(valid);

  menu(&user);

  return NO_ERROR;
}
// gcc main.c -o main src/*.c -Wall -Iinclude -lcrypto -lm