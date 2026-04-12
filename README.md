# Trabalho 2: Order Book - Sistema de Ordens de Compra e Venda

## Descrição do Projeto
Simulação de um sistema de compra e venda:
- **Matching:** Uma transação ocorre quando o preço de uma ordem de compra é maior ou igual ao melhor preço de venda disponível.
- **Prioridade:** O sistema organiza as ordens por **Preço** e, em caso de empate, pelo **Timestamp** (prioridade temporal).
- **Cancelamento:** Permite a remoção de ordens do livro antes de serem executadas através do ID único.

## Organização do Código
* `main.cpp`: Testes automatizados cobrindo inserção, match, cancelamento e exibição.
* `OrderBook.cpp/hpp`: Gerenciador principal do sistema.
* `System.cpp/hpp`: Implementação das listas encadeadas.
* `Order.cpp/hpp`: Classe que representa os dados de uma ordem.
* `Transaction.cpp/hpp`: Classe que representa os dados de uma transação.

## Instruções de Compilação
No terminal, utilize o seguinte comando para compilar todos os módulos:

```bash
g++ main.cpp OrderBook.cpp Order.cpp Transaction.cpp System.cpp -o order_book