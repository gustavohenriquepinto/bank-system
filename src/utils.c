#include "../include/utils.h"

#include "../include/report.h"
#include "../include/transaction.h"
#include "../include/user.h"

void utilsMenu() {
  User* user = userGet();
  int action = -1;

  while (action < 0 || action > 5) {
    utilsClearTerminal();
    puts("O que você deseja?");
    puts("0. Sair");
    puts("1. Consultar saldo");
    puts("2. Realizar um depósito");
    puts("3. Realizar um saque");
    puts("4. Realizar uma transferência");
    puts("5. Gerar um relatório");

    scanf("%d", &action);
    printf("%c\n", action == 0);

    if (action == 0) break;
    if (action == 1) accountPrint(&(user->account));
    if (action == 2) accountDepositMenu(&(user->account));
    if (action == 3) accountWithdrawalMenu(&(user->account));
    if (action == 4) transactionMenu(&(user->account));
    if (action == 5) reportMenu(&(user->account));
  }

  if (action == 0) return userLogin();
  puts("Aperte enter para retornar ao menu");
  system("pause");
  utilsMenu();
}

void utilsClearTerminal() {
  system("clear");
  system("cls");
}

bool utilsCompareIfIsSameString(char* str1, char* str2) {
  return strcmp(str1, str2) == 0 ? true : false;
}
