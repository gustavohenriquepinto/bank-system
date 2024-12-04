#include "../include/utils.h"

#include "../include/report.h"
#include "../include/transaction.h"
#include "../include/user.h"

void utilsMenu() {
  User* user = userGet();
  int action = -1;

  utilsClearTerminal();
  puts("O que voce deseja?");
  puts("0. Sair");
  puts("1. Consultar saldo");
  puts("2. Realizar um deposito");
  puts("3. Realizar um saque");
  puts("4. Realizar uma transferencia");
  puts("5. Gerar um relatorio");

  fflush(stdin);
  scanf("%d", &action);
  fflush(stdin);

  if (action < 0 || action > 5) return utilsMenu();
  if (action == 0) return userLogin();
  if (action == 1) accountPrint(&(user->account));
  if (action == 2) accountDepositMenu(&(user->account));
  if (action == 3) accountWithdrawalMenu(&(user->account));
  if (action == 4) transactionMenu(&(user->account));
  if (action == 5) reportMenu(&(user->account));

  utilsPause();
  utilsMenu();
}

void utilsClearTerminal() {
  system("cls");
  system("clear");
}

void utilsPause() {
  char action;
  fflush(stdin);
  puts("Pressione qualquer tecla para continuar:");
  scanf("%c", &action);
  fflush(stdin);
}

bool utilsCompareIfIsSameString(char* str1, char* str2) {
  return strcmp(str1, str2) == 0 ? true : false;
}
