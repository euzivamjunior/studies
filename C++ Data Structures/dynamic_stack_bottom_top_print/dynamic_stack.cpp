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
        // create a tempNode to go throught the stack
        Node* tempNode;
        /*
            go through the stack deleting the nodes until the tempNode reaches 
            the nullptr value, always creating a refenrence to TopNode as 
            tempNode, then change the TopNode to the next node, and delete the 
            previus TopNode by the tempNode reference.
        */
        while (TopNode != nullptr){
            tempNode = TopNode;
            TopNode = TopNode->next;
            delete tempNode;
        }
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
        // create a Node pointer named 'newNode'
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
        if (is_full()){
            cout << "There's no memory available for alocate a new element" << endl;
            cout << "The element can't be pushed" << endl;
        } else{
            // create a Node pointer "newNode"
            Node* newNode = new Node;
            // set item value to the new node
            // as newNode is a pointer, then the assignment is made with "->"
            newNode->value = item;
            // set TopNode as newNode.next
            newNode->next = TopNode;
            // set TopNode as newNode
            TopNode = newNode;
        }
    }
    // remove an element from the dynamic stack
    ItemType DynamicStack::pull(){
        if (is_empty()){
            cout << "The stack is empty!" << endl;
            cout<< "There's no element to pull." << endl;
            return 0;
        } else {
            /*
                Create a temp node, that pointer to the current top node
                in this way, after remove the current top node from stack, 
                it can be possible to delete this node from the memory by 
                using the tempNode.
            */
            Node* tempNode;
            tempNode = TopNode;
            // catch value from TopNode
            ItemType item = TopNode->value;
            // the new TopNode becomes the next Node from the current TopNode
            TopNode = TopNode->next;
            // delete tempNode that are reference to the current removed Node
            delete tempNode;
            // return item (value) from the removed Node
            return item;
        }
    }
    // print all elements in the dynamic stack
    void DynamicStack::print(){
        // check if the list is empty
        if (is_empty()){
            cout << " empty " << endl;
            return;
        }
        // create a tempNode to go throught the stack
        Node* tempNode = TopNode;
        Node* nextNode = tempNode->next;
        
        if (nextNode == nullptr){
            cout << tempNode->value << " ";
            return;
        }
        TopNode = tempNode->next;
        DynamicStack::print();
        TopNode = tempNode;
        cout << tempNode->value << " ";
    }