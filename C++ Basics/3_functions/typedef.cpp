#include <iostream>
#include <typeinfo>
using namespace std;


// typedef keyword is used to assign a new name 
// to any existing data-type.
typedef int id;

// typedef long counter; // c++ 10 bellow
using counter = long; // c++ 11 above


int main() {
    id a = 5;
    counter b = 10;

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

    return 0;
}