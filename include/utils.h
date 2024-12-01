#ifndef UTILS_H
#define UTILS_H

#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"

#define DATE_ASCENDING_SORT 0
#define DATE_DESCENDING_SORT 1
#define VALUE_ASCENDING_SORT 2
#define VALUE_DESCENDING_SORT 3

#define STRING_MAX 256
#define STRING_READ "%255s"

typedef char SortMode;
typedef int Number;
typedef long int Money;

typedef int PAYMENT_METHOD;
#define PIX 0
#define TED 1
#define BILL 2

void utilsMenu();
void utilsClearTerminal();
bool utilsCompareIfIsSameString(char*, char*);

#endif