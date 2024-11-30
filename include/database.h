#ifndef DATABASE_H
#define DATABASE_H

#include "transaction.h"
#include "transactionList.h"
#include "user.h"
#include "utils.h"

void databaseInitialize();
int databaseGetAmountOfUsersRegisters();
ErrorController databaseInsertUser(User* user);
ErrorController databaseRemoveUser(User* user);
ErrorController databaseGetUser(char* email, User* user);
bool databaseHasUser(char* email);

#endif