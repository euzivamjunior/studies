#include <iostream>
using namespace std;

int main () {

    double pi = 3.14;
    double& piRef = pi;

    // * -> dereference operator
    // Think of as "Get Value At..."
    cout << pi << endl;
    cout << &pi << endl;
    cout << *&pi << endl;
    cout << &*&pi << endl;

    // * is used to creater a pointer!

    return 0;
}