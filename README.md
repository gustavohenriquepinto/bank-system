# PROJETO FINAL

## Implementação
- Linguagem C
- Interface Gráfica Multiplataforma <gtk/gtk.h> (não essencial) (v3.24.43)
- Criptografia de Dados <openssl/crypto.h>

- Inteiro para números
- Uso no terminal

- Tempo do programa: 1dia, 1min

nomeDaFUNÇÃO (camel case) //functions
NOME_DA_CONSTANTE (upper snake case) //consts
nome_da_variavel (snake case) //vars
NomeDaEstrutura (pascal case) //structs

## Objetivos
- Pilhas, filas e/ou listas ligadas. (Transaction)
- Ponteiros e alocação dinâmica de memória. (Lists)
- Métodos de pesquisa (pesquisa sequencial e/ou pesquisabinária). (Files)
- Métodos de ordenação (bubble sort, insertion sort, selection sort e/ou merge sort) (Transaction)

## Requisitos Funcionais Essenciais
- Criação, edição e exclusão de contas
- Definição de tipo de conta (corrente/poupança)
- Consultas ao saldo
- Depósitos e saques

- Atribuição de saldo inicial
- Transferências entre contas (TED, PIX, CARTÃO_DE_CRÉDITO)
- Gerenciamento de limite de cartão de crédito

- Histórico de transferências (filtros)
- Emissão de extratos, com a possibilidade de utilizar filtros ou ordenação
- Filtros
- - Data/Período
- - Valor
- - Tipo

### Segurança e Privacidade
- Autenticação de Usuários
- Criptografia de Dados (files)

### Desempenho e Escalabilidade
- Velocidade de Resposta
- Permitir crescimento na base de usuários

### Usabilidade
- Interface Intuitiva e Amigável

## Requisitos de Negócio
- Ter uma conta bancária funcional capaz de interagir com outras contas.
- Escalabilidade e Custo de Operação: 
O sistema deve ser projetado para ser economicamente viável e capaz de escalar à medida que o número de clientes aumenta, sem que haja custos excessivos de infraestrutura.