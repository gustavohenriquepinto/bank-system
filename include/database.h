#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "utils.h"

ErrorController databaseInsertUser(User* user);
ErrorController databaseRemoveUser(User* user);
ErrorController databaseGetUser(char* email, User* user);
bool databaseHasUser(char* email);

#endif