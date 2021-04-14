#include <iostream>
#include "dynamic_queue.h"
// to use nullptr
#include <cstddef>
// to use bad_alloc exception
#include <new>

using namespace std;

    DynamicQueue::DynamicQueue(){
        front = nullptr;
        rear = nullptr;
    }
    DynamicQueue::~DynamicQueue(){
        /*
            go through the nodes deleting then until the front pointer 
            reaches the end of the queue, i.e. when the front is equal 
            to nullptr. At end of Nodes destruction, the rear is set
            as nullptr;
        */
        Node* tempNode;
        while (front != nullptr){
            tempNode = front;
            front = front->next;
            delete tempNode;
        }
        rear = nullptr;
    }

    bool DynamicQueue::is_empty(){
        // if front is nullptr, then the queue is empty
        return (front == nullptr);
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
    bool DynamicQueue::is_full(){
        // create a Node pointer named 'newNode'
        Node* newNode;
        // try to create a new node
        try{
            newNode = new Node;
            delete newNode;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }
    void DynamicQueue::enqueue(ItemType item){
        // check if there are mamemory available
        if (is_full()){
            cout << "There's no memory available for alocate a new element" << endl;
            cout << "The element can't be inserted" << endl;
        /* 
            create a newNode. If front is nullptr, then the front becomes the
            reference for the newNode, if not nullptr, then the quere already 
            have an front node, so the current rear node receive the next 
            reference to the newNode, and the newNode becomes to be referenced 
            by the rear pointer. 

            - The rear will always reference to the newNode enqueued.
        */
        } else{
            // the new is used to allow deletion of the newNode
            Node* newNode = new Node;
            newNode->value = item;
            newNode->next = nullptr;
            if (front == nullptr){
                front = newNode;
            } else{
                rear->next = newNode;
            }
            rear = newNode;
        }
    }
    ItemType DynamicQueue::dequeue(){
        if (is_empty()){
            cout << "The queue is empty!" << endl;
            cout<< "There's no element to remove." << endl;
            return 0;
        /*
            Create a newNode referencing to the current front Node
            catch the value from the front Node, then front changes
            the reference to the next Node.
            If front is nullptr, then, there's no more Nodes in the
            queue, and the rear pointer also becomes nullptr.
        */
        } else{
            Node* newNode = front;
            ItemType item = front->value;
            front = front->next;
            if (front == nullptr){
                rear = nullptr;
            }
            delete newNode;
            return item;
        }
    }
    void DynamicQueue::print(){
        Node* newNode = front;
        cout << "Queue = [ ";
        while (newNode != nullptr){
            cout << newNode->value << " ";
            newNode = newNode->next;
        }
        cout << "]\n";
    }