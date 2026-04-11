#include <iostream>
# include "System.hpp"

Node::Node(Order order){
    this -> order = order;
    this -> next = nullptr;
    this -> prev = nullptr;
}

DoubleLinkedList::DoubleLinkedList(bool sortDescending){
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> size = 0;
    this -> sortDescending = sortDescending;
}

void DoubleLinkedList::insertSorted(Order order){
    Node* newNode = new Node(order);

    if (head == nullptr) {
            head = tail = newNode;
            size++; 
            return;
    } 

    float price = order.getPrice();
    int timestamp = order.getTimestamp();
    Node* current = head;


    while (current != nullptr) {
        bool InsertBefore = false;
        if (this -> sortDescending) {
            if(price > current -> order.getPrice()) {
                InsertBefore = true;
            } else if (price == current -> order.getPrice() && timestamp < current -> order.getTimestamp()) {
                InsertBefore = true;

            }
        } else {
            if(price < current -> order.getPrice()) {
                InsertBefore = true;
            } else if (price == current -> order.getPrice() && timestamp < current -> order.getTimestamp()) {
                InsertBefore = true;

            }
        }

        if (InsertBefore) {
            break;
        }

        current = current -> next;


    }

    if (current == nullptr) {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    } else if (current == head) {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    } else {
        newNode -> next = current;
        newNode -> prev = current -> prev;
        current -> prev -> next = newNode;
        current -> prev = newNode;
    }

    size++;
}

Order DoubleLinkedList::getFront(){
    if (head != nullptr) {
        return head -> order;
    }
    return Order(-1, ' ', 0, 0); // Retorna uma ordem inválida se a lista estiver vazia
}

void DoubleLinkedList::removeEnd(){
    if (tail == nullptr) return;

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
    size--;
}

void DoubleLinkedList::removeFront(){
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    size--;
}

void DoubleLinkedList::remove(Order order){
    Node* current = head;
    while (current != nullptr && current -> order.getId() != order.getId()) {
        current = current -> next;
    }

    if (current == nullptr) return;

    if (current == head) {
        removeFront();
        return;
    }

    if (current == tail) {
        removeEnd();
        return;
    }

    current -> prev -> next = current -> next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

int DoubleLinkedList::getSize(){
    return this -> size;
}

Order* DoubleLinkedList::getOrdersArray() {

    if (size == 0) {
        return nullptr;
    }

    Order* arr = new Order[size];
    
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        arr[count] = current->order; 
        current = current->next;
        count++;
    }
    return arr;
}


TransactionNode::TransactionNode(Transaction transaction) : transaction(transaction) {
    this->next = nullptr;
}


TransactionList::TransactionList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void TransactionList::addTransaction(Transaction transaction) {
    TransactionNode* newNode = new TransactionNode(transaction);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void TransactionList::printTransactions() {
    TransactionNode* current = head;
    while (current != nullptr) {
        std::cout << "Transaction -> Buy ID: " << current->transaction.getBuyOrderId() 
                  << " | Sell ID: " << current->transaction.getSellOrderId() 
                  << " | Price: " << current->transaction.getExecutionPrice() << std::endl;
        current = current->next;
    }
}

int TransactionList::getSize() {
    int count = 0;
    TransactionNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}



Transaction* TransactionList::getTransactionsArray() {
    int size = getSize();
    if (size == 0) return nullptr;

    Transaction* arr = new Transaction[size];
    int count = 0;
    TransactionNode* current = head;
    while (current != nullptr) {
        arr[count] = current->transaction;
        current = current->next;
        count++;
    }
    return arr;
}
