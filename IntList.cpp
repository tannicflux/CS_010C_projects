#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    // Create dummy head and tail nodes
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    // Link dummy head and tail nodes
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList() {
    // Delete all nodes until the list is empty
    while(!empty()) {
        pop_front();
    }

    // Delete dummy head and tail nodes
    delete dummyHead;
    delete dummyTail;
}

void IntList::push_front(int value) {
    // Create a new node with the given value
    IntNode *temp = new IntNode(value);

    // Insert the new node at the front of the list
    temp->next = dummyHead->next;
    temp->prev = dummyHead;
    dummyHead->next->prev = temp;
    dummyHead->next = temp;
}

void IntList::pop_front() {
    // Check if the list is empty
    if(dummyHead->next == dummyTail) {
        return;
    }

    // Remove the node at the front of the list
    IntNode *temp = dummyHead->next;
    dummyHead->next = temp->next;
    temp->next->prev = dummyHead;
    delete temp;
}

void IntList::push_back(int value) {
    // Create a new node with the given value
    IntNode *temp = new IntNode(value);

    // Insert the new node at the back of the list
    temp->prev = dummyTail->prev;
    temp->next = dummyTail;
    dummyTail->prev->next = temp;
    dummyTail->prev = temp;
}

void IntList::pop_back() {
    // Check if the list is empty
    if(dummyTail->prev == dummyHead) {
        return;
    }

    // Remove the node at the back of the list
    IntNode *temp = dummyTail->prev;
    dummyTail->prev = temp->prev;
    temp->prev->next = dummyTail;
    delete temp;
}

bool IntList::empty() const {
    // Check if the list is empty by comparing the next node of dummyHead with dummyTail
    return dummyHead->next == dummyTail;
}

ostream &operator<<(ostream &out, const IntList &rhs) {
    // Start from the first node
    IntNode *current = rhs.dummyHead->next;

    // Traverse the list until the dummy tail node
    while(current != rhs.dummyTail) {
        out << current->data;

        // Add a space after each node except the last one
        if(current->next != rhs.dummyTail) {
            out << " ";
        }

        // Move to the next node
        current = current->next;
    }

    return out;
}

void IntList::printReverse() const {
    // Start from the last node
    IntNode *current = dummyTail->prev;

    // Traverse the list in reverse until the dummy head node
    while(current != dummyHead) {
        cout << current->data << " ";

        // Move to the previous node
        current = current->prev;
    }
}