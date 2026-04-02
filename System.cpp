# include "System.hpp"

Node::Node(Order order){
    this -> order = order;
    this -> next = nullptr;
    this -> prev = nullptr;
}

DoubleLinkedList::DoubleLinkedList(){
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> size = 0;
}

void DoubleLinkedList::insert(Order order){
    Node* newNode = new Node(order);

    if (tail == nullptr) {
            head = tail = newNode;
    } else{
            tail -> next = newNode;;
            newNode -> prev = tail;
            tail = newNode;
    }

    size++;

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