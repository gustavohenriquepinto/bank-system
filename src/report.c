#include "../include/report.h"

#include "../include/database.h"
#include "../include/user.h"

int times_reported = 0;

void reportMenu() {
  utilsClearTerminal();
  int action = -1;
  puts("Deseja gerar qual relatório?");
  puts("0. Voltar");
  puts("1. Extrato geral");
  puts("1. Saques/Depositos");
  puts("2. Transfências");
  puts("3. Receitas");
  puts("4. Despesas");

  scanf("%d", &action);
  if (action == 0) error(NO_ERROR, MAIN_MENU);

  // pendente
  error(NO_ERROR, REPORT_MENU);
}

void printAllUsers() {
  int read = 0;
  FILE* user_file = databaseGetUserFile();
  fseek(user_file, 0, SEEK_SET);

  utilsClearTerminal();
  while (!feof(user_file)) {
    User user;
    read = fread(&user, sizeof(User), 1, user_file);
    if (!read) break;

    printf("Conta: %d\n", user.account.number);
    printf("Nome: %s\n", user.name);
    printf("Email: %s\n", user.email);
    printf("Saldo: ");
    accountPrintMoney(user.account.balance);
    puts("----------------------------------------------------");
  }
  system("pause");
}