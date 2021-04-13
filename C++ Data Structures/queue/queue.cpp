#include <iostream>
#include "queue.h"

using namespace std;

    // constructor
    Queue::Queue(){
        first = 0;
        last = 0;
        // create new structure with type[num_itens]
        structure = new ItemType[max_itens];
    }
    // destructor
    Queue::~Queue(){
        delete[] structure;
    }

    // check if queue is full
    bool Queue::is_full(){
        return (last - first == max_itens);
    }
    // check if queue is empty
    bool Queue::is_empty(){
        return (first == last);
    }
    // insert an element in the queue
    void Queue::enqueue(ItemType item){
        // queue is full?
        if (is_full()){
            cout << "Queue is already full!" << endl;
            cout<< "The element can't be enqueued." << endl;
        } else {
            /* 
            structure[remainder of division]
            Thus, the index of the vector has a circular characteristic
            where any number greater than the max index of the the vector
            is converter to the begining of the vector. ex:
            For max index = 4, the index 5 becomes 0, index 6 becomes 1, 
            and so on.
            */
            structure[last % max_itens] = item;
            last++;
        }
    }
    // remove an element from the queue
    ItemType Queue::dequeue(){
        // queue is empty?
        if (is_empty()){
            cout << "Queue is empty!" << endl;
            cout<< "There's no element to dequeue." << endl;
            return 0;
        } else {
            first++;
            /*
            structure[remainder of division]
            How we increment 'first' var before the return statement,
            it needed to decrement first index inside the return statement.
            thus, the correct element is returned.
            */
            return structure[(first - 1) % max_itens];
        }
    }
    // print all elements in the queue
    void Queue::print(){
        cout<< "Queue: [ ";
        for (int index=first; index<last; index++){
            // structure[remainder of division]: circular characteristic vector
            cout << structure[index % max_itens] << " ";
        }
        cout << "]";
    }
    // return lenght (number) of elements on the stack
    int Queue::lenght(){
        return (last - first);
    }