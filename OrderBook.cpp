// Implementação da classe OrderBook

#include <iostream>
#include "OrderBook.hpp"
#include "Transaction.hpp"

// buy_orders(true): lista de compras ordenada de forma decrescente
// sell_orders(false): lista de vendas ordenada de forma crescente
OrderBook::OrderBook(): buy_orders(true), sell_orders(false) {
    this -> num_orders = 0;
} 

OrderBook::~OrderBook(){

}

bool OrderBook::submit(Order order){
    int id = order.getId();
    char type = order.getType();
    float price = order.getPrice();
    int timestamp = order.getTimestamp();

    if (type == 'B') {

        if (sell_orders.getSize() > 0) {
            Order bestSell = sell_orders.getFront();
            if (price >= bestSell.getPrice()) {
                Transaction transaction(id, bestSell.getId(), bestSell.getPrice());
                transactions.addTransaction(transaction);
                sell_orders.removeFront();
                return true;
            }
        }


        buy_orders.insertSorted(order);
        this -> num_orders++;
        return false;

    } else if (type == 'S') {
        if (buy_orders.getSize() > 0) {
            Order bestBuy = buy_orders.getFront();
            if (price <= bestBuy.getPrice()) {
                Transaction transaction(bestBuy.getId(), id, bestBuy.getPrice());
                transactions.addTransaction(transaction);
                buy_orders.removeFront();
                return true;
            }
        }

        sell_orders.insertSorted(order);
        this -> num_orders++;
        return false;
    } else {
        return false; 
    }

}

bool OrderBook::cancel(int id) {
    Order dummy(id, ' ', 0, 0);
    int initialSize = buy_orders.getSize();
    buy_orders.remove(dummy);
    if (buy_orders.getSize() < initialSize) {
        this -> num_orders--;
        return true;

    } 

    int initialSellSize = sell_orders.getSize();
    sell_orders.remove(dummy);
    if (sell_orders.getSize() < initialSellSize) {
        this -> num_orders--;
        return true;
    }

    return false;

}


void OrderBook::printBuyOrders() {
    int size = buy_orders.getSize();
    if (size == 0) {
        std::cout << "No buy orders." << std::endl;
        return;
    }   
    Order* orders = buy_orders.getOrdersArray();
    for (int i = 0; i < size; i++) {
        std::cout << "Buy Order -> ID: " << orders[i].getId()
                    << " | Price: " << orders[i].getPrice() 
                    << " | Timestamp: " << orders[i].getTimestamp() << std::endl;       

    }

    delete[] orders;  

}

void OrderBook::printSellOrders() {
    int size = sell_orders.getSize();
    if (size == 0) {
        std::cout << "No sell orders." << std::endl;
        return;
    }   
    Order* orders = sell_orders.getOrdersArray();
    for (int i = 0; i < size; i++) {
        std::cout << "Sell Order -> ID: " << orders[i].getId()
                    << " | Price: " << orders[i].getPrice() 
                    << " | Timestamp: " << orders[i].getTimestamp() << std::endl;       

    }

    delete[] orders;  
}

void OrderBook::printTransactions() {
    transactions.printTransactions();
}


Order* OrderBook::getBuyOrders(int* n) {
    *n = buy_orders.getSize();
    if (*n == 0) {
        return nullptr;
    }
    return buy_orders.getOrdersArray();
}

Order* OrderBook::getSellOrders(int* n) {
    *n = sell_orders.getSize();
    if (*n == 0) {
        return nullptr;
    }
    return sell_orders.getOrdersArray();
}

Transaction* OrderBook::getTransactions(int* n) {
    *n = transactions.getSize();
    if (*n == 0) {
        return nullptr;
    }
    return transactions.getTransactionsArray();
}