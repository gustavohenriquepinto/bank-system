#include "../include/database.h"

FILE* user_file;
int user_size = 0;

FILE* transaction_list;
int transaction_size;

void databaseInitialize() {
  user_file = fopen("users.data", "ab+");
  fseek(user_file, 0, SEEK_END);
  user_size = ftell(user_file) / sizeof(User);

  transaction_list = fopen("transactions.data", "ab+");
  fseek(transaction_list, 0, SEEK_END);
  transaction_size = ftell(transaction_list) / sizeof(Transaction);
}

FILE* databaseGetUserFile() { return user_file; }

bool databaseHasUser(char* email) {
  rewind(user_file);
  while (!feof(user_file)) {
    User user;
    fread(&user, sizeof(User), 1, user_file);
    fread(&(user.account), sizeof(Account), 1, user_file);
    if (utilsCompareIfIsSameString(email, user.email)) return true;
  }
  return false;
}

ErrorController databaseGetUser(char* email, User* user) {
  rewind(user_file);
  fseek(user_file, 0, SEEK_SET);
  while (!feof(user_file)) {
    User user_temp;
    fread(&user_temp, sizeof(User), 1, user_file);
    if (utilsCompareIfIsSameString(email, user_temp.email)) {
      *user = user_temp;
      return NO_ERROR;
    }
  }
  return USER_DOENST_EXIST_ERROR;
}

int databaseGetAmountOfUsersRegisters() { return user_size; }

ErrorController databaseInsertUser(User* user) {
  fseek(user_file, 0, SEEK_END);
  fwrite(user, sizeof(User), 1, user_file);
  user_size++;
  return NO_ERROR;
}

ErrorController databaseInsertTransaction(Transaction* transaction) {
  fseek(transaction_list, 0, SEEK_END);
  fwrite(transaction, sizeof(Transaction), 1, transaction_list);
  transaction_size++;
  return NO_ERROR;
}

ErrorController databaseGetAccountByNumber(Number number, Account* account) {
  rewind(user_file);
  fseek(user_file, 0, SEEK_SET);
  User user;
  while (!feof(user_file)) {
    fread(&user, sizeof(User), 1, user_file);
    if (user.account.number == number) {
      *account = user.account;
      return NO_ERROR;
    }
  }
  return USER_DOENST_EXIST_ERROR;
}

ErrorController databaseUpdateAccount(Account* account, Money value) {
  rewind(user_file);
  fseek(user_file, 0, SEEK_SET);
  User user;
  while (!feof(user_file)) {
    fread(&user, sizeof(User), 1, user_file);
    if (user.account.number == account->number) {
      fseek(user_file, -1 * sizeof(User), SEEK_CUR);
      user.account.balance = value;
      fwrite(&user, 1, sizeof(User), user_file);
      return NO_ERROR;
    }
  }
  return USER_DOENST_EXIST_ERROR;
}

ErrorController databaseAddTransaction(Transaction* transaction) {
  rewind(transaction_list);
  fseek(transaction_list, 0, SEEK_END);
  fwrite(transaction, sizeof(Transaction), 1, transaction_list);
  return NO_ERROR;
}

ErrorController databasePrintTransactions() {
  rewind(transaction_list);
  fseek(transaction_list, 0, SEEK_SET);
  Transaction transaction;
  puts("Transações:");
  while (!feof(transaction_list)) {
    fread(&transaction, sizeof(Transaction), 1, transaction_list);
    puts(transactionText(&transaction));
  }
  return NO_ERROR;
}