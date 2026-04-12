#include "Order.hpp"
#include "Transaction.hpp"

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

class Node {
public:
    Order order; // para criação da lista duplamente encadeada de Order
    Node* next;
    Node* prev;

    Node(Order order);
};

class DoubleLinkedList { 
private:
    Node* head;
    Node* tail;
    int size;
    bool sortDescending; // permite inserção ordenada por preço

public:
    DoubleLinkedList(bool sortDescending = true);
    void insertSorted(Order order);
    void removeFront();
    void removeEnd();
    void remove(Order order);
    int getSize();
    Order* getOrdersArray();
    Order getFront();
    ~DoubleLinkedList();
};

class TransactionNode{
public:
    Transaction transaction;
    TransactionNode* next;

    TransactionNode(Transaction transaction);
};

class TransactionList {
private:
    TransactionNode* tail;
    TransactionNode* head;
public:
    TransactionList();
    void addTransaction(Transaction transaction);
    void printTransactions();
    int getSize();  
    Transaction* getTransactionsArray();
    ~TransactionList();
};

#endif