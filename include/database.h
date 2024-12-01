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
ErrorController databaseInsertUser(User* user);
ErrorController databaseRemoveUser(User* user);
ErrorController databaseGetUser(char* email, User* user);

ErrorController databaseGetAccountByNumber(Number number, Account* account);

#endif