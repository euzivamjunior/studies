#include <iostream>
using namespace std;

int main () {
    // array index:  0,  1,  2,  3,  4
    int values[] = {31, 44, 58, 91, 25};

    // this array size calculus doesn't work for pointers
    cout << "Size of array: " 
         << sizeof(values) / sizeof(*values) << endl;
    
    for(int index = 0; index < 5; index++) {
        cout << index << "\t" << values[index] << endl;
    }

    // index out of range: 'garbage'... random value...
    cout << "value for index out of range: " << values[6] << endl;

    return 0;
}