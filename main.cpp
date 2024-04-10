#include "IntList.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    IntList list;

    // Test empty on an empty list
    assert(list.empty() == true);

    // Test push_front
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    cout << "After push_front: " << list << endl;

    // Test empty on a non-empty list
    assert(list.empty() == false);

    // Test push_back
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    cout << "After push_back: " << list << endl;

    // Test printReverse
    cout << "Print in reverse: ";
    list.printReverse();
    cout << endl;

    // Test pop_front
    list.pop_front();
    cout << "After pop_front: " << list << endl;

    // Test pop_back
    list.pop_back();
    cout << "After pop_back: " << list << endl;

    // Test operator<<
    cout << "List: " << list << endl;

    return 0;
}