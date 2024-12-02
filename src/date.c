#include "../include/date.h"

#include <time.h>

#include "../include/utils.h"

#define BASE_DAY 1
#define BASE_MONTH 1
#define BASE_YEAR 1900

char days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void initializeDate(Date* date) { *date = 0; }

bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
  if (month == 2 && isLeapYear(year)) return 29;
  return days_in_months[month - 1];
}

Date convertIntegersToDate(int day, int month, int year) {
  Date date;
  initializeDate(&date);
  for (int y = BASE_YEAR; y < year; y++) date += isLeapYear(y) ? 366 : 365;
  for (int m = 1; m < month; m++) date += daysInMonth(m, year);
  date += day - 1;
  return date;
}

// Public
Date newDate(int day, int month, int year) {
  if (day < 1 || day > daysInMonth(month, year)) return INVALID_DAY_ERROR;
  if (month < 1 || month > 12) return INVALID_MONTH_ERROR;
  if (year < BASE_YEAR) return INVALID_YEAR_ERROR;

  return convertIntegersToDate(day, month, year);
}

Date now() {
  time_t t = time(NULL);
  struct tm* tm_info = localtime(&t);
  int day = tm_info->tm_mday;
  int month = tm_info->tm_mon + 1;     // tm_mon começa em 0
  int year = tm_info->tm_year + 1900;  // tm_year conta a partir de 1900

  return newDate(day, month, year);
}

char* dateText(Date date) {
  char* result = malloc(11 * sizeof(char));
  int year = BASE_YEAR;
  int month = BASE_MONTH;
  int day = BASE_DAY;

  while (date >= (isLeapYear(year) ? 366 : 365)) {
    date -= isLeapYear(year) ? 366 : 365;
    year++;
  }

  while (date >= daysInMonth(month, year)) {
    date -= daysInMonth(month, year);
    month++;
  }

  day += date;

  sprintf(result, "%02d/%02d/%04d", day, month, year);

  return result;
}
