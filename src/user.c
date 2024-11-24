#include "../include/user.h"

void userInitialize(User *user) {
  user->name = malloc(STRING_MAX * sizeof(char));
  user->email = malloc(STRING_MAX * sizeof(char));
}

void userFree(User *user) {
  free(user->name);
  free(user->email);
}

bool userSignUp() {
  User user;
  char *password = malloc(STRING_MAX * sizeof(char));
  char *confirm_password = malloc(STRING_MAX * sizeof(char));

  utilsClearTerminal();
  userInitialize(&user);

  puts("Vamos criar sua conta");

  puts("Digite seu nome completo:");
  scanf(STRING_READ, user.name);

  puts("Digite seu e-mail:");
  scanf(STRING_READ, user.email);

  puts("Digite sua senha de acesso:");
  scanf(STRING_READ, password);

  puts("Confirme sua senha:");
  scanf(STRING_READ, confirm_password);

  if (!utilsCompareIfIsSameString(password, confirm_password)) return false;
  initializeEncryptedPassword(&user.password, password);

  puts("Chegamos aqui");

  userFree(&user);
  free(password);
  free(confirm_password);

  return true;
}

bool userSignIn() {
  char *email = malloc(STRING_MAX * sizeof(char));
  char *password = malloc(STRING_MAX * sizeof(char));

  utilsClearTerminal();

  printf("Digite seu e-mail: ");
  scanf(STRING_READ, email);

  // função para achar usuario
  // return USER_DOENST_EXIST_ERROR

  printf("Digite sua senha: ");
  scanf(STRING_READ, password);

  puts("usuario logado");

  free(email);
  free(password);

  return true;
}

bool userLogin() {
  int action;

  utilsClearTerminal();
  puts("Bem vindo ao Finance Bank, como deseja prosseguir?");
  puts("1. Entrar na sua conta");
  puts("2. Criar uma conta");
  scanf("%d", &action);

  if (action == 1) return userSignIn();
  if (action == 2) return userSignUp();

  return false;
}