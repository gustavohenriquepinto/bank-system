#ifndef DATABASE_H
#define DATABASE_H

#include "user.h"
#include "utils.h"

bool databseInsertUser(User* user);
ErrorController databaseHasUser(char* email);

#endif