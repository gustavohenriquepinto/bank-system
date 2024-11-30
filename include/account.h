#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "utils.h"

#define NO_MONEY 0
#define MONEY_LIMIT 9223372036854775807

typedef struct {
  Number number;
  Money balance;
} Account;

void initializeAccount(Account*);
void accountPrint(Account*);
void accountPrintMoney(Money);
void accountDepositMenu(Account*);
void accountWithdrawalMenu(Account*);

Money accountGetBalance(Account*);
ErrorController accountIncreaseBalance(Account*, Money);
ErrorController accountDecreaseBalance(Account*, Money);

#endif