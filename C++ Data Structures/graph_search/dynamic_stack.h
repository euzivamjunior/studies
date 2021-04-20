#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include "node.h"

class DynamicStack{
    private:
    // pointer to top node
    Node* TopNode;

    public:
    // constructor
    DynamicStack();
    // destructor
    ~DynamicStack();
    // check if dynamic stack is empty
    bool is_empty();
    // check if there are memory available to a new node
    bool is_full();
    // insert an element in the dynamic stack
    void push(ItemType item);
    // remove an element from the dynamic stack
    ItemType pull();
    // print all elements in the dynamic stack
    void print();
};

#endif
