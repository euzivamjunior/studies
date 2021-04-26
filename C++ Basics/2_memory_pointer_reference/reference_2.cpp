#include <iostream>
using namespace std;

int main () {
    /*
        Why not " int& xRef = &x; " ?
        -------------------------------------
        At compile time all instances of xRef
        are replaced with the address of 'x'
    */

    int x = 7;
    int& xRef = x;

    cout << x << "\t" << &x << endl;
    cout << xRef << "\t" << &xRef << endl;

    xRef++;

    cout << x << "\t" << &x << endl;
    cout << xRef << "\t" << &xRef << endl;

    x++;

    cout << x << "\t" << &x << endl;
    cout << xRef << "\t" << &xRef << endl;

    return 0;
}