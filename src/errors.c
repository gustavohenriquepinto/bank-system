#include "../include/errors.h"

#include "../include/report.h"
#include "../include/transaction.h"
#include "../include/user.h"
#include "../include/utils.h"

void error(int errorCode, int to) {
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
      puts("Senha de confirmacao diferente.");
      break;

    case INSUFICCIENT_MONEY_ERROR:
      puts("Saldo insuficiente.");
      break;

    case NEGATIVE_NUMBER_ERROR:
      puts("Digite um valor positivo.");
      break;

    case ENTER_ANOTHER_ACCOUNT_NUMBER:
      puts("Digite um numero de outra conta.");
      break;

    default:
      break;
  }

  if (to == HOME) {
    puts("Voce sera redirecionado para a tela de inicial:");
    utilsPause();
    return userLogin();
  }

  if (to == SIGN_UP) {
    puts("Voce sera redirecionado para a tela de cadastro:");
    utilsPause();
    return userSignUp(userGet());
  }

  if (to == SIGN_IN) {
    puts("Voce sera redirecionado para a tela de login:");
    utilsPause();
    return userSignIn(userGet());
  }

  if (to == MAIN_MENU) {
    puts("Voce sera redirecionado para o menu principal:");
    utilsPause();
    return utilsMenu();
  }

  if (to == TRANSACTION_MENU) {
    puts("Voce sera redirecionado para o menu transferencias:");
    utilsPause();
    return transactionMenu(&(userGet()->account));
  }

  if (to == REPORT_MENU) {
    puts("Voce sera redirecionado para o menu relatorios:");
    utilsPause();
    return reportMenu(&(userGet()->account));
  }
}