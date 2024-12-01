#ifndef ERRORS_H
#define ERRORS_H

typedef int ErrorController;

#define NO_ERROR 0
#define LOGOUT 1

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

// Erros em Estruturas Auxiliares
#define INVALID_DAY_ERROR 401
#define INVALID_MONTH_ERROR 402
#define INVALID_YEAR_ERROR 403

void error(int);

#endif