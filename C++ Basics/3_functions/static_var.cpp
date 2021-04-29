#include <iostream>
using namespace std;


int nextId() {
    // static: is executed only once during 
    // function (or scope) initialization
    static int id = 1;

    // first return id, then id++ (increment)
    return id++;
}


int main() {
    cout << nextId() << endl;
    cout << nextId() << endl;
    cout << nextId() << endl;
    cout << nextId() << endl;
    cout << nextId() << endl;

    return 0;
}