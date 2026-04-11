// Arquivo principal contendo testes para todas as funções implementadas.
#include <iostream>
#include "OrderBook.hpp"
#include "Order.hpp"

int main() {
    OrderBook book;
    int id = 1;
    int timestamp_buy = 1;
    int timestamp_sell = 1;

    std::cout << "--- Testando Envio ---" << std::endl;
    book.submit(Order(id, 'B', 100.0, timestamp_buy++)); // Buy order
    book.submit(Order(++id, 'S', 110.0, timestamp_sell++));  // Sell order

    book.printBuyOrders();
    book.printSellOrders();
    book.printTransactions();

    std::cout << "--- Testando Match Melhor ---" << std::endl;

    book.submit(Order(++id, 'B', 109.0, timestamp_buy++)); // Buy order
    book.submit(Order(++id, 'S', 90, timestamp_sell++));  // Sell order
    book.submit(Order(++id, 'S', 110, timestamp_sell++));  // Sell order
    book.printBuyOrders();
    book.printSellOrders();
    book.printTransactions();

    std::cout << "--- Testando Timestamp de Desempate ---" << std::endl;



    book.submit(Order(++id, 'B', 110, timestamp_buy++));  // Buy order
    book.printBuyOrders();
    book.printSellOrders();
    book.printTransactions();

    std::cout << "--- Testando Cancelamento ---" << std::endl;

    book.cancel(1); // Cancelar ordem de compra com ID 1
    book.printBuyOrders();
    book.cancel(2);
    book.printSellOrders();

}