#include "../include/report.h"

#include "../include/database.h"
#include "../include/user.h"

int times_reported = 0;

/*

typedef int PAYMENT_METHOD;
#define PIX 1
#define TED 2
#define BILLET 3
#define DEPOSIT 4
#define WITHDRAWAL 5

*/

void reportMenu() {
  utilsClearTerminal();
  int action = -1;
  SortMode sort = DATE_ASCENDING_SORT;
  PAYMENT_METHOD method;

  puts("Deseja gerar qual relatório?");
  puts("0. Voltar");
  puts("1. Extrato geral");
  scanf("%d", &action);
  if (action == 0) error(NO_ERROR, MAIN_MENU);
  if (action != 1) error(NO_ERROR, REPORT_MENU);

  utilsClearTerminal();
  puts("Ordernar por:");
  puts("0. Data em ordem crescente");
  puts("1. Data em ordem decrescente");
  puts("2. Valor em ordem crescente");
  puts("3. Valor em ordem decrescente");
  scanf("%d", &sort);

  utilsClearTerminal();
  puts("Filtrar por:");
  puts("0. Todos");
  puts("1. Pix");
  puts("2. TED");
  puts("3. Boleto");
  puts("4. Depósito");
  puts("5. Saque");
  scanf("%d", &method);

  printRequest(userGet(), sort, method);
  error(NO_ERROR, MAIN_MENU);
}

void printRequest(User* user, SortMode sort, PAYMENT_METHOD filter) {
  LIST_Transaction transactions;
  initList(&transactions);

  databaseGetUserTransactions(user, &transactions);
  filterList(&transactions, filter);
  sortList(&transactions, sort);

  printList(&transactions);
  freeList(&transactions);
}

void printAllUsers() {
  FILE* user_file = databaseGetUserFile();
  fseek(user_file, 0, SEEK_SET);

  utilsClearTerminal();

  User user;
  while (fread(&user, sizeof(User), 1, user_file) == 1) {
    printf("Conta: %d\n", user.account.number);
    printf("Nome: %s\n", user.name);
    printf("Email: %s\n", user.email);
    accountPrintMoney(user.account.balance);
    puts("----------------------------------------------------");
  }

  system("pause");
}

void printAllTransactions() {
  int x = 0;
  FILE* transaction_file = databaseGetTransactionFile();
  rewind(transaction_file);
  fseek(transaction_file, 0, SEEK_SET);

  utilsClearTerminal();
  puts("Extrato Geral");
  puts("----------------------------------------------------");

  Transaction transaction;
  while (fread(&transaction, sizeof(Transaction), 1, transaction_file) == 1) {
    x++;
    printf("%d -> ", x);
    printf("Data: %s\n", dateText(transaction.date));
    printf("Valor R$ %.2f\n", transaction.value / 100.0);

    printf("De %s para %s\n\n", transaction.origin.name,
           transaction.destiny.name);
    puts("----------------------------------------------------");
  }

  system("pause");
}

void printDepositsAndWithdrawal() {
  int x = 0;
  FILE* transaction_file = databaseGetTransactionFile();
  rewind(transaction_file);
  fseek(transaction_file, 0, SEEK_SET);

  utilsClearTerminal();
  puts("----------------------------------------------------");
  puts("Extrato Geral");
  while (!feof(transaction_file)) {
    x++;
    Transaction transaction;
    fread(&transaction, sizeof(Transaction), 1, transaction_file);
    if (!feof(transaction_file) &&
        (transaction.method == DEPOSIT || transaction.method == WITHDRAWAL)) {
      printf("%d -> ", x);
      printf("%s - ", dateText(transaction.date));
      accountPrintMoney(transaction.value);

      printf("De %s para %s\n\n", transaction.origin.name,
             transaction.destiny.name);
    }
  }
}
