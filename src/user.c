#include "../include/user.h"

#include "../include/database.h"
#include "../include/password.h"

int serial_account = 1;

void userInitialize(User *user) {
  user->account.balance = 0;
  user->account.number = serial_account++;
}

void userGetString(char *message, char *destiny) {
  fflush(stdin);
  printf("%s", message);
  scanf(STRING_READ, destiny);
  fflush(stdin);
}

ErrorController userSignUp(User *user) {
  char password[STRING_MAX];
  char confirm_password[STRING_MAX];

  utilsClearTerminal();

  puts("Vamos criar sua conta");

  userGetString("Digite seu nome: ", user->name);
  userGetString("Digite seu email: ", user->email);
  userGetString("Digite sua senha: ", password);
  userGetString("Confirme sua senha: ", confirm_password);

  if (!utilsCompareIfIsSameString(password, confirm_password)) {
    error(DIFFERENT_PASSWORDS_ERROR);
    return DIFFERENT_PASSWORDS_ERROR;
  }

  passwordEncrypted(password, user->password);
  databaseInsertUser(user);

  return NO_ERROR;
}

ErrorController userSignIn(User *user) {
  char email[STRING_MAX];
  char password[STRING_MAX];

  utilsClearTerminal();
  userGetString("Digite seu email: ", email);
  if (!databaseHasUser(email)) return USER_DOENST_EXIST_ERROR;

  databaseGetUser(email, user);
  printf("Usuário = %s\n", user->name);
  printf("Email = %s\n", user->email);
  printf("Senha = %s\n", user->password);

  userGetString("Digite sua senha: ", password);

  if (!passwordIsCorrect(password, user->password))
    return INCORRECT_PASSWORD_ERROR;

  return NO_ERROR;
}
