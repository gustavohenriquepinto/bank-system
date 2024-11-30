#ifndef UTILS_H
#define UTILS_H

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
#define STRING_READ "%255[^\n]"

typedef char SortMode;
typedef long int Number;
typedef long int Money;

typedef long int PAYMENT_METHOD;
#define TED 0
#define BILLET 1
#define PIX 2

void utilsClearTerminal();
bool utilsCompareIfIsSameString(char*, char*);

#endif