#include <iostream>
#include "dynamic_stack.h"
#include <cstddef>

using namespace std;

    // constructor
    DynamicStack::DynamicStack(){
        TopNode = nullptr;
    }
    // destructor
    DynamicStack::~DynamicStack(){

    }
    // check if dynamic stack is empty
    bool DynamicStack::is_empty(){
        return(TopNode == nullptr);
    }
    /*
        CHECK IF THERE ARE MEMORY AVAILABLE TO ALOCATE A NEW NODE
        -------------------------------------------------------------
        To know if there are memory available to alocate a new node,
        we 'try' to alocate a new node, if it works, then, there are
        memory available, if not, the catch(bad_alloc exception) will 
        return true, meaning that there's no memory available for a 
        new node. 
    */
    bool DynamicStack::is_full(){
        // create a pointer named 'newNode'
        Node* newNode;
        // try create a new node
        try{
            newNode = new Node;
            delete newNode;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }
    // insert an element in the dynamic stack
    void DynamicStack::push(ItemType item){

    }
    // remove an element from the dynamic stack
    ItemType DynamicStack::pull(){

    }
    // print all elements in the dynamic stack
    void print(){

    }