#include <iostream>
using namespace std;

int main() {

    int x = 5; // stack;

    /*
        Once the memory is alocated in heap for a variable
        or object, it's really important to delete this alocation
        when the use of the object is ended.

        In the heap memory, we create, we exclude.

    // new ==> malloc() + constructor
    // delete ==> free() + destructor
    */

    int* y = new int(10); // heap 4 bytes
    cout << x* (*y) << endl; 
    delete y;

    int* w = new int[100]; // 4bytes * 100 = 400 bytes
    w[49] = 123;
    cout << w[45] << endl;
    // delete[] ==> to delete all the elements
    delete[] w;

    return 0;
}