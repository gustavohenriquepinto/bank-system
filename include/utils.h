#ifndef UTILS_H
#define UTILS_H

#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"

typedef int SortMode;
#define DATE_ASCENDING_SORT 0
#define DATE_DESCENDING_SORT 1
#define VALUE_ASCENDING_SORT 2
#define VALUE_DESCENDING_SORT 3

#define STRING_MAX 256
#define STRING_READ "%255s"

typedef int Number;
typedef long int Money;

typedef int PAYMENT_METHOD;
#define ALL 0
#define PIX 1
#define TED 2
#define BILLET 3
#define DEPOSIT 4
#define WITHDRAWAL 5

void utilsMenu();
void utilsPause();
void utilsClearTerminal();
bool utilsCompareIfIsSameString(char*, char*);

#endif