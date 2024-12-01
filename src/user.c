#include "../include/user.h"

#include "../include/database.h"
#include "../include/password.h"
#include "../include/report.h"
#include "../include/utils.h"

User user;

User* userGet() { return &user; }

void userGetString(char* message, char* destiny) {
  fflush(stdin);
  printf("%s", message);
  scanf(STRING_READ, destiny);
  fflush(stdin);
}

ErrorController userSignUp() {
  char* password = malloc(STRING_MAX * sizeof(char));
  char* confirm_password = malloc(STRING_MAX * sizeof(char));

  utilsClearTerminal();
  puts("Vamos criar sua conta:");
  userGetString("Digite seu nome: ", user.name);

  userGetString("Digite seu email: ", user.email);
  if (databaseHasUser(user.email)) return USER_ALREADY_EXIST_ERROR;

  userGetString("Digite sua senha: ", password);
  userGetString("Confirme sua senha: ", confirm_password);
  if (!utilsCompareIfIsSameString(password, confirm_password)) {
    free(password);
    free(confirm_password);
    return DIFFERENT_PASSWORDS_ERROR;
  }

  initializeAccount(&user.account);
  passwordEncrypted(password, user.password);
  free(password);
  free(confirm_password);

  return databaseInsertUser(&user);
}

ErrorController userSignIn() {
  char* email = malloc(STRING_MAX * sizeof(char));
  char* password = malloc(STRING_MAX * sizeof(char));
  ErrorController valid = NO_ERROR;

  utilsClearTerminal();
  userGetString("Digite seu email: ", email);
  if (!databaseHasUser(email)) return USER_DOENST_EXIST_ERROR;

  valid = databaseGetUser(email, &user);
  if (valid != NO_ERROR) return valid;

  userGetString("Digite sua senha: ", password);
  if (!passwordIsCorrect(password, user.password))
    return INCORRECT_PASSWORD_ERROR;

  return NO_ERROR;
}

void userLogin() {
  int action = -1;
  ErrorController valid = NO_ERROR;

  while (action < 0 || action > 2) {
    utilsClearTerminal();
    puts("Bem vindo ao Finance Bank, como deseja prosseguir?");
    puts("0. Encerrar programa");
    puts("1. Entrar na sua conta");
    puts("2. Criar uma conta");
    scanf("%d", &action);

    if (action == 0) valid = LOGOUT;
    if (action == 1) valid = userSignIn();
    if (action == 2) valid = userSignUp();
    if (action == 3) printAllUsers();
  }

  if (valid == LOGOUT) exit(EXIT_SUCCESS);
  if (valid == NO_ERROR) return utilsMenu();
  error(valid);
}