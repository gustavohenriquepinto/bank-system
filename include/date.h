#ifndef DATE_H
#define DATE_H

typedef int Date;

Date newDate(int day, int month, int year);
Date now();
char* dateText(Date date);

#endif