#ifndef REPORT_H
#define REPORT_H

#include "user.h"
#include "utils.h"

void reportMenu();
void printAllUsers();
void printAllTransactions();
void printDepositsAndWithdrawal();
void printRequest(User*, SortMode, PAYMENT_METHOD);

#endif