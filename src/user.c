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

ErrorController userSignUp(User *user) {
  char *password = malloc(STRING_MAX * sizeof(char));
  char *confirm_password = malloc(STRING_MAX * sizeof(char));

  utilsClearTerminal();
  userInitialize(user);

  puts("Vamos criar sua conta");

  userGetString("Digite seu nome: ", user->name);
  userGetString("Digite seu email: ", user->email);
  userGetString("Digite sua senha: ", password);
  userGetString("Confirme sua senha: ", confirm_password);

  if (!utilsCompareIfIsSameString(password, confirm_password)) {
    free(password);
    free(confirm_password);
    return error(DIFFERENT_PASSWORDS_ERROR);
  }

  userConfigurePassword(user, password);
  databaseInsertUser(user);

  free(password);
  free(confirm_password);

  return true;
}

ErrorController userSignIn(User *user) {
  char email[STRING_MAX];
  char password[STRING_MAX];
  userGetString("Digite seu email: ", email);

  if (!databaseHasUser(email)) return USER_DOENST_EXIST_ERROR;

  databaseGetUser(email, user);

  userGetString("Digite sua senha: ", password);

  if (!passwordIsCorrect(user->password, password))
    return INCORRECT_PASSWORD_ERROR;

  return NO_ERROR;
}
