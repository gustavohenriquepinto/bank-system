#include "../include/report.h"

int times_reported = 0;

// man, vamo tentar rodar o código? ok
// tem acessso ao terminal agr?
// yes

ErrorController reportMenu() {
  int action = -1;
  puts("Deseja gerar qual relatório?");
  puts("0. Voltar");
  puts("1. Saques/Depositos");
  puts("2. Extrato bancario");
  puts("3. Receitas");
  puts("4. Despesas");

  scanf("%d", &action);

  // if(action >= 0 && action <= 4)

  switch (action) {
    case -1:
      return INVALID_ACTION_ERROR;
    case 0:
      return NO_ERROR;
    case 1:
    case 2:
    case 3:
    case 4:
  }

  return NO_ERROR;
}
