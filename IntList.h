#ifndef UNTITLED_INTLIST_H
#define UNTITLED_INTLIST_H

#include <iostream>

using namespace std;

// Node structure for the doubly linked list
struct IntNode {
    int data; // Data stored in the node
    IntNode *prev; // Pointer to the previous node
    IntNode *next; // Pointer to the next node
    IntNode(int data) : data(data), prev(0), next(0) {} // Constructor to initialize the node
};

// Class representing a doubly linked list with dummy head and tail nodes
class IntList {
private:
    IntNode *dummyHead; // Dummy head node
    IntNode *dummyTail; // Dummy tail node
public:
    IntList(); // Constructor to initialize the list
    ~IntList(); // Destructor to delete all nodes and prevent memory leaks
    void push_front(int value); // Method to add a node at the front of the list
    void pop_front(); // Method to remove a node from the front of the list
    void push_back(int value); // Method to add a node at the back of the list
    void pop_back(); // Method to remove a node from the back of the list
    bool empty() const; // Method to check if the list is empty
    friend ostream &operator<<(ostream &out, const IntList &rhs); // Overloaded operator<< to print the list
    void printReverse() const; // Method to print the list in reverse order
};

#endif //UNTITLED_INTLIST_H