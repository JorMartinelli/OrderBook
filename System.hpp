#include "Order.hpp"

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

class Node {
public:
    Order order;
    Node* next;
    Node* prev;

    Node(Order order);
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList();
    void insert(Order order);
    void removeFront();
    void removeEnd();
    void remove(Order order);
    int getSize();
    Order* getOrdersArray();
};

#endif