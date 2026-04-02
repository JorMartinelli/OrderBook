// Implementação da classe OrderBook

#include "OrderBook.hpp"
#include "Transaction.hpp"

OrderBook::OrderBook(){
    this -> num_orders = 0;
    this -> system = DoubleLinkedList();
}

OrderBook::~OrderBook(){

}

bool OrderBook::submit(Order order){
    int id = order.getId();
    char type = order.getType();
    float price = order.getPrice();
    int timestamp = order.getTimestamp();

    int size = system.getSize();

    Order* list_orders = system.getOrdersArray();
}