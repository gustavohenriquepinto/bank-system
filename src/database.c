#include "../include/database.h"

#include "../include/report.h"
#include "../include/user.h"

User FINANCE_BANK;

FILE* user_file;
int user_size = 0;

FILE* transaction_file;
int transaction_size;

void databaseInitialize() {
  user_file = fopen("users.data", "a");
  fclose(user_file);

  user_file = fopen("users.data", "r+b");
  fseek(user_file, 0, SEEK_END);

  user_size = ftell(user_file) / sizeof(User);
  if (!user_size) {
    strcpy(FINANCE_BANK.name, "Finance Bank");
    strcpy(FINANCE_BANK.email, "financebank@email.com");
    strcpy(FINANCE_BANK.password, "password");
    FINANCE_BANK.account.balance = 1000000000;
    FINANCE_BANK.account.number = 0;
    databaseInsertUser(&FINANCE_BANK);
  }

  transaction_file = fopen("transactions.data", "a");
  fclose(transaction_file);

  transaction_file = fopen("transactions.data", "r+b");
  fseek(transaction_file, 0, SEEK_END);
  transaction_size = ftell(transaction_file) / sizeof(Transaction);
}

FILE* databaseGetUserFile() { return user_file; }

bool databaseHasUser(char* email) {
  rewind(user_file);
  User user;
  while (fread(&user, sizeof(User), 1, user_file) == 1)
    if (utilsCompareIfIsSameString(email, user.email)) return true;

  return false;
}

ErrorController databaseUpdateUser(User* user) {
  fseek(user_file, 0, SEEK_SET);
  User user_temp;
  long position = 0;

  while (fread(&user_temp, sizeof(User), 1, user_file) == 1) {
    if (utilsCompareIfIsSameString(user->email, user_temp.email)) {
      fseek(user_file, position, SEEK_SET);
      fwrite(user, sizeof(User), 1, user_file);
      return NO_ERROR;
    }
    position = ftell(user_file);
  }

  return USER_DOENST_EXIST_ERROR;
}

ErrorController databaseGetUser(char* email, User* user) {
  rewind(user_file);
  fseek(user_file, 0, SEEK_SET);
  while (!feof(user_file)) {
    User user_temp;
    fread(&user_temp, sizeof(User), 1, user_file);
    if (utilsCompareIfIsSameString(email, user_temp.email)) {
      *user = user_temp;
      user->account = user_temp.account;
      return NO_ERROR;
    }
  }
  return USER_DOENST_EXIST_ERROR;
}

int databaseGetAmountOfUsersRegisters() { return user_size; }

ErrorController databaseInsertUser(User* user) {
  if (databaseHasUser(user->email)) return USER_ALREADY_EXIST_ERROR;

  fseek(user_file, 0, SEEK_END);
  fwrite(user, sizeof(User), 1, user_file);
  user_size++;
  return NO_ERROR;
}

ErrorController databaseInsertTransaction(Transaction* transaction) {
  fseek(transaction_file, 0, SEEK_END);
  fwrite(transaction, sizeof(Transaction), 1, transaction_file);
  transaction_size++;
  return NO_ERROR;
}

ErrorController databaseGetUserTransactions(User* user,
                                            LIST_Transaction* list) {
  rewind(transaction_file);
  Transaction transaction;
  while (fread(&transaction, sizeof(Transaction), 1, transaction_file)) {
    if (user->account.number == transaction.origin.account.number ||
        user->account.number == transaction.destiny.account.number)
      pushBackList(list, &transaction);
  }
  return NO_ERROR;
}

ErrorController databaseGetUserByAccountNumber(Number number, User* user) {
  fseek(user_file, 0, SEEK_SET);
  User temp_user;
  while (fread(&temp_user, sizeof(User), 1, user_file) == 1) {
    if (temp_user.account.number == number) {
      *user = temp_user;
      return NO_ERROR;
    }
  }
  return USER_DOENST_EXIST_ERROR;
}

FILE* databaseGetTransactionFile() { return transaction_file; }
