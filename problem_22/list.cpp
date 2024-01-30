#include "list.h"
#include <iostream>

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(const Name& value) {
    Node* new_node = new Node(value);

    if (head == nullptr || value.get_name() < head->data.get_name()) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* current = head;

        while (current->next != nullptr && current->next->data.get_name() < value.get_name()) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    int i = 0;
    Node* current = head;
    while (current != nullptr) {
        current->data.set_index(i++);
        current->data.update_score();
        current = current->next;
    }
}

void LinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data.get_name() << " " << current->data.get_score() << '\n';
        current = current->next;
    }
    std::cout << '\n';
}

long long LinkedList::sum_scores() {
    long long sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->data.get_score();
        current = current->next;
    }
    return sum;
}