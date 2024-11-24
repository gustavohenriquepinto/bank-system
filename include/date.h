#ifndef DATE_H
#define DATE_H

#include "utils.h"

typedef int Date;

Date newDate(int day, int month, int year);
bool firstIsMoreRecent(Date date1, Date date2);

#endif