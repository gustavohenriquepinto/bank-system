#include "../include/utils.h"

void utilsClearTerminal() {
  system("cls");
  system("clear");
}

bool utilsCompareIfIsSameString(char* str1, char* str2) {
  return strcmp(str1, str2) == 0 ? true : false;
}
