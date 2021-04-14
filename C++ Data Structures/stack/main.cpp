#include <iostream>
#include "stack.h"

using namespace std;

int main(){
    // instantiate an object
    Stack stack1;
    // def item as ItemType type
    ItemType item;
    // control variable - while loop
    int control;

    // Output title script
    cout << "Script Stack Generator:" << endl;
    
    do {
        // Main options message, to interact with script
        cout << endl << "Type 0 to stop the script!" << endl;
        cout << "Type 1 to insert a element!" << endl;
        cout << "Type 2 to remove a element!" << endl;
        cout << "Type 3 to print the stack elements" << endl;
        cout << "Type 4 to print the length of the stack" << endl;

        cin >> control;

        // to insert an element
        if (control == 1){
            cout << "Type the element to be inserted: " << endl;
            cin >> item;
            stack1.push(item);
        // to remove an element
        } else if (control == 2){
            item = stack1.pop();
            if (item != 0){
                cout << "Element removed" << endl;
            }
        // to print all stack elements
        } else if (control == 3){
            stack1.print();
        // to print the stack length
        } else if (control == 4){
            cout << "The length of the stack is: " << stack1.length() << endl;
        }

    // exit the while loop
    } while(control != 0);

    return 0;
}