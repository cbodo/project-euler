#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "name.h"

class Node {
public:
    Name data;
    Node* next;

    Node(const Name& value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void insert(const Name& value);
    void display();
};

#endif
