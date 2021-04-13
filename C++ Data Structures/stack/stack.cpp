#include <iostream>
#include "stack.h"

using namespace std;

    // constructor
    Stack::Stack(){
        size = 0;
        // create new structure with type[num_itens]
        structure = new ItemType[max_itens];
    }
    // destructor
    Stack::~Stack(){
        // delete vector structure
        delete[] structure;
    }

    // check if stack is full (on max item number)
    bool Stack::is_full(){
        return (size == max_itens);
    }
    // check if stack is empty
    bool Stack::is_empty(){
        return (size == 0);
    }
    // add an element to the stack
    void Stack::push(ItemType item){
        // stack is full?
        if (is_full()){
            cout << "Stack is already full!" << endl;
            cout<< "The element can't be pushed." << endl;
        } else{
            // add item in structure[index_current_size]
            structure[size] = item;
            // size increment
            size ++;
            /*
                for each element pushed, we have, vector index element = n,
                size (number of elements in a vector) = n + 1.
                This occurs because the index vector start with 0.
            */
        }
    }
    // remove an element from stack
    ItemType Stack::pop(){
        // stack is empty?
        if (is_empty()){
            cout << "Stack is empty!" << endl;
            cout<< "There's no element to pop." << endl;
            return 0;
        } else{
            // decrement size and return structure element
            size--;
            return structure[size];
        }
    }
    // print all elements on the stack
    void Stack::print(){
        cout << "Stack: [ ";
        for (int index=0; index<size; index++){
            cout << structure[index] << " ";
        }
        cout << "]" << endl;
    }
    // return lenght (number) of elements on the stack
    int Stack::lenght(){
        return size;
    }