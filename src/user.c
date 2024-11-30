#include "../include/user.h"

#include "../include/database.h"

void userInitialize(User *user) {
  user->name = malloc(STRING_MAX * sizeof(char));
  user->email = malloc(STRING_MAX * sizeof(char));
}

void userConfigurePassword(User *user, char *password) {
  initializeEncryptedPassword(&(user->password), password);
}

void userFree(User *user) {
  free(user->name);
  free(user->email);
  free(user->password);
}

void userGetString(char *message, char *destiny) {
  printf("%s", message);
  scanf(STRING_READ, destiny);
}

bool userSignUp() {
  User user;
  char *password = malloc(STRING_MAX * sizeof(char));
  char *confirm_password = malloc(STRING_MAX * sizeof(char));

  utilsClearTerminal();
  userInitialize(&user);

  puts("Vamos criar sua conta");

  userGetString("Digite seu nome: ", user.name);
  userGetString("Digite seu email: ", user.email);
  userGetString("Digite sua senha: ", password);
  userGetString("Confirme sua senha: ", confirm_password);

  if (!utilsCompareIfIsSameString(password, confirm_password)) {
    userFree(&user);
    free(password);
    free(confirm_password);
    return false;
  }
  userConfigurePassword(&user, password);

  puts("Chegamos aqui");

  userFree(&user);
  free(password);
  free(confirm_password);

  return true;
}

int userSignIn() {
  char *email = malloc(STRING_MAX * sizeof(char));
  char *password = malloc(STRING_MAX * sizeof(char));

  userGetEmail(email);

  if (!databaseHasUser(email)) {
    puts("Usuário não existe.");
    free(email);
    return USER_DOENST_EXIST_ERROR;
  }

  userGetPassword(password);

  puts("usuario logado");

  free(email);
  free(password);

  return NO_ERROR;
}
