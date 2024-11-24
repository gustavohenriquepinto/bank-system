# PROJETO FINAL

## Implementação
- Linguagem C
- Interface Gráfica Multiplataforma <gtk/gtk.h>
- Criptografia de Dados <openssl/crypto.h>

- Inteiro para números
- Uso no terminal

- Tempo do programa: 1dia, 1min


## Objetivos
- Pilhas, filas e/ou listas ligadas. (CRON, TED)
- Ponteiros e alocação dinâmica de memória
- Métodos de pesquisa (pesquisa sequencial e/ou pesquisabinária)
- Métodos de ordenação (bubble sort, insertion sort, selection sort e/ou merge sort)

## Observações
- Em tempo de compilação: Ações instâneas não irão para pilha
- CRON: Ações programadas irão para uma pilha controlada manualmente (boleto, ted)

- O CRON com a fila seria a continuidade do tempo, sendo executada 4x (60seg/4) por dia

## Requisitos Funcionais Essenciais
- Criação, edição e exclusão de contas
- Definição de tipo de conta (corrente/poupança)
- Consultas ao saldo
- Depósitos e saques

// Conta corrente/poupança
// render 0.1% a cada 30seg

// SIAC

- Atribuição de saldo inicial
- Transferências entre contas (TED, PIX, CARTÃO_DE_CRÉDITO)
- Gerenciamento de limite de cartão de crédito
// valor de transação da conta / qtd meses
// benefícios: cashback

// TED: enquanto não for tempo x, reinserir no topo da fila
// PIX: imediato

- Geração e pagamento de boletos
// desconta na hora
// confirmado após 2 dias
// código de barra

- Histórico de transferências (filtros)
- Emissão de extratos, com a possibilidade de utilizar filtros ou ordenação
- Filtros
- - Data/Período
- - Valor
- - Espécie
- - Destinatário

- Controle de faturas e vencimentos
- Pagamento de contas de serviços (energia, internet, água, etc.)

- Realização de empréstimos (linha de crédito da conta) (prazos, juros e valores)
// min: 20k max: 1m

## Requisitos Funcionais Não Essenciais
- Limitação de transferências diárias (diário ou noturno)
- Pagamento de tributos (impostos, taxas, IPVA, IPTU)
- Pagamentos parcelados pela instituição

- Investimentos em renda fixa e/ou variável (fictício)
- Consulta aos valores atuais de moedas, criptomoedas e ações (fictício)
- Realização de financiamentos (linha de crédito da conta) (prazos, juros e valores)

## Requisitos Não-Funcionais

### Segurança e Privacidade
- Autenticação de Usuários
- Criptografia de Dados (files)
- Controle e Histórico de Acesso (log), tentar salvar o ip

### Desempenho e Escalabilidade
- Velocidade de Resposta
- Permite o crescimento na base de usuários

### Usabilidade
- Interface Intuitiva e Amigável
- Personalização de Temas (se tiver, apenas no <gtk/gtk.h>) (não essencial)

## Requisitos de Negócio
- Ter uma conta bancária funcional capaz de interagir com outras contas.
- Escalabilidade e Custo de Operação: O sistema deve ser projetado para ser economicamente viável e capaz de escalar à medida que o número de clientes aumenta, sem que haja custos excessivos de infraestrutura.