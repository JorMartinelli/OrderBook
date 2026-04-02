// Declaração da classe OrderBook

#include "Order.hpp"
#include "Transaction.hpp"
#include "System.hpp"

#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

class OrderBook {

private:

    int num_orders;
    DoubleLinkedList system;

public:

    OrderBook();
    ~OrderBook();

    bool submit(Order order);
    bool cancel(int id);

    Order* getBuyOrders(int* n);
    Order* getSellOrders(int* n);
    Transaction* getTransactions(int* n);

    void printBuyOrders();
    void printSellOrders();
    void printTransactions();

    // Outros métodos auxiliares, se necessário
};

#endif