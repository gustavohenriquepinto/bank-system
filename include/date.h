#ifndef DATE_H
#define DATE_H

#include <stdbool.h>

#define INVALID_DAY_ERROR -1
#define INVALID_MONTH_ERROR -2
#define INVALID_YEAR_ERROR -3

typedef int Date;

Date newDate(int day, int month, int year);
bool firstIsMoreRecent(Date date1, Date date2);

#endif