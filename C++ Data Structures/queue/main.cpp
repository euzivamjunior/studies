#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue queue1;
    int control;
    ItemType item;

    cout << "Queue Generator" << endl;

    do{
        // Main options message, to interact with script
        cout << endl << "Type 0 to stop the script!" << endl;
        cout << "Type 1 to insert a element!" << endl;
        cout << "Type 2 to remove a element!" << endl;
        cout << "Type 3 to print the stack elements" << endl;
        cout << "Type 4 to print the lenght of the queue" << endl;

        cin >> control;

        // to insert an element
        if (control == 1){
            cout << "Type the element to be enqueued: " << endl;
            cin >> item;
            queue1.enqueue(item);

        // to remove an element
        } else if (control == 2){
            item = queue1.dequeue();
            if (item != 0){
                cout << "Element dequeued" << endl;
            }
        // to print all stack elements
        } else if (control == 3){
            queue1.print();
        } else if (control == 4){
            cout << "The lenght of the queue is: " << queue1.lenght() << endl;
        }

    // exit the while loop
    } while(control != 0);

    return 0;
}