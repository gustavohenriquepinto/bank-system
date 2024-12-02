#ifndef DATABASE_H
#define DATABASE_H

#include "transaction.h"
#include "transactionList.h"
#include "user.h"
#include "utils.h"

void databaseInitialize();
int databaseGetAmountOfUsersRegisters();
bool databaseHasUser(char* email);

FILE* databaseGetUserFile();
<<<<<<< HEAD
ErrorController databaseInsertUser(User* user);
ErrorController databaseRemoveUser(User* user);
ErrorController databaseGetUser(char* email, User* user);
ErrorController databaseUpdateAccount(Account* user, Money value);
ErrorController databaseGetAccountByNumber(Number number, Account* account);
=======
FILE* databaseGetTransactionFile();

ErrorController databaseInsertUser(User*);
ErrorController databaseUpdateUser(User*);
ErrorController databaseRemoveUser(User*);
ErrorController databaseGetUser(char* email, User*);
ErrorController databaseGetUserByAccountNumber(Number account_number, User*);

ErrorController databaseInsertTransaction(Transaction*);
ErrorController databaseGetUserTransactions(User* user, LIST_Transaction* list);
>>>>>>> 3763a82296f5e6a65c977ce9b327c88a511b6056

ErrorController databaseAddTransaction(Transaction* transaction);
ErrorController databasePrintTransactions();

#endif