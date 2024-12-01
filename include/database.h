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
ErrorController databaseInsertUser(User*);
ErrorController databaseUpdateUser(User*);
ErrorController databaseRemoveUser(User*);
ErrorController databaseGetUser(char* email, User*);
ErrorController databaseGetUserByAccountNumber(Number account_number, User*);

ErrorController databaseInsertTransaction(Transaction*);

#endif