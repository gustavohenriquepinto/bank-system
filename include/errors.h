#ifndef ERRORS_H
#define ERRORS_H

typedef int ErrorController;

#define NO_ERROR 0
#define LOGOUT 1
#define HOME 2
#define SIGN_UP 3
#define SIGN_IN 4
#define MAIN_MENU 5
#define TRANSACTION_MENU 6
#define REPORT_MENU 7

// Erros Globais
#define INPUT_ERROR 101
#define INVALID_ACTION_ERROR 102

// Erros de Usuário
#define USER_DOENST_EXIST_ERROR 201
#define USER_ALREADY_EXIST_ERROR 202
#define INCORRECT_PASSWORD_ERROR 203
#define DIFFERENT_PASSWORDS_ERROR 204

// Erros em Transações
#define INSUFICCIENT_MONEY_ERROR 301
#define MONEY_LIMIT_ERROR 302
#define NEGATIVE_NUMBER_ERROR 303
#define ENTER_ANOTHER_ACCOUNT_NUMBER 304

// Erros em Estruturas Auxiliares
#define INVALID_DAY_ERROR 401
#define INVALID_MONTH_ERROR 402
#define INVALID_YEAR_ERROR 403

void error(int, int);

#endif