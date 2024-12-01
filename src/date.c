#include "../include/date.h"

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

char* dateToText(Date date) {
  int year = BASE_YEAR;
  int remainingDays = date;
  for (; year < BASE_YEAR + 3000 && remainingDays >= 365; year++) {
    remainingDays -= isLeapYear(year) ? 366 : 365;
  }

  int month = 1;
  for (; month <= 12 && remainingDays >= daysInMonth(month, year); month++) {
    remainingDays -= daysInMonth(month, year);
  }

  int day = remainingDays + 1;

  char result[11];
  sprintf(result, "%02d/%02d/%04d", day, month, year);
  return result;
}

bool firstIsMoreRecent(Date date1, Date date2) { return date1 >= date2; }
