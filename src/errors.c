#include "../include/errors.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/user.h"

void error(int errorCode) {
  switch (errorCode) {
    case INPUT_ERROR:
      puts("Infelizmente seu input nao pode ser processado.");
      break;

    case USER_ALREADY_EXIST_ERROR:
      puts("Usuario ja cadastrado.");
      break;

    case USER_DOENST_EXIST_ERROR:
      puts("Usuario nao encontrado.");
      break;

    case INCORRECT_PASSWORD_ERROR:
      puts("Senha incorreta.");
      break;

    case DIFFERENT_PASSWORDS_ERROR:
      puts("Senha de confirmação diferente.");
      break;

    default:
      break;
  }

  puts("Voce sera redirecionado para a tela de login novamente:");
  system("pause");
  userLogin();
}