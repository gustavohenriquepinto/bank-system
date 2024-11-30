#include "../include/errors.h"

#include <stdio.h>

void error(int errorCode) {
  switch (errorCode) {
    case INPUT_ERROR:
      printf("Infelizmente seu input não pode ser processado.");
      break;

    case USER_DOENST_EXIST_ERROR:
      printf("Usuário não encontrado.");
      break;

    default:
      break;
  }

  printf("Você será redirecionado para a tela de login novamente");
  // userLogin();
}