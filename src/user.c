#include "../include/user.h"

#include "../include/database.h"
#include "../include/password.h"
#include "../include/report.h"

User user;

User *userGet() { return &user; };

void userInitialize(User *user) {
  user->account.balance = 0;
  user->account.number = databaseGetAmountOfUsersRegisters() + 1;
}

void userGetString(char *message, char *destiny) {
  fflush(stdin);
  printf("%s", message);
  scanf(STRING_READ, destiny);
  fflush(stdin);
}

void userSignUp(User *user) {
  char password[STRING_MAX];
  char confirm_password[STRING_MAX];

  utilsClearTerminal();
  puts("Vamos criar sua conta");
  userGetString("Digite seu nome: ", user->name);
  userGetString("Digite seu email: ", user->email);
  userGetString("Digite sua senha: ", password);
  userGetString("Confirme sua senha: ", confirm_password);

  if (!utilsCompareIfIsSameString(password, confirm_password)) {
    return error(DIFFERENT_PASSWORDS_ERROR, SIGN_UP);
  }

  passwordEncrypted(password, user->password);
  databaseInsertUser(user);
}

void userSignIn(User *user) {
  char email[STRING_MAX];
  char password[STRING_MAX];

  utilsClearTerminal();
  userGetString("Digite seu email: ", email);
  if (databaseGetUser(email, user) != NO_ERROR)
    return error(USER_DOENST_EXIST_ERROR, SIGN_IN);

  userGetString("Digite sua senha: ", password);
  if (!passwordIsCorrect(password, user->password))
    return error(INCORRECT_PASSWORD_ERROR, SIGN_IN);
}

void userLogin() {
  int action = -1;

  userInitialize(&user);
  while (action < 0 || action > 2) {
    utilsClearTerminal();
    puts("Bem vindo ao Finance Bank, como deseja prosseguir?");
    puts("0. Encerrar programa");
    puts("1. Entrar na sua conta");
    puts("2. Criar uma conta");
    scanf("%d", &action);

    if (action == 0) exit(EXIT_SUCCESS);
    if (action == 1) userSignIn(&user);
    if (action == 2) userSignUp(&user);
    if (action == 3) printAllUsers();
  }

  utilsMenu();
}
