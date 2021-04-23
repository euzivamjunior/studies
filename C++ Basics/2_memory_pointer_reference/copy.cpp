#include <iostream>
using namespace std;

int main () {
    int a = 2;
    int b = a;  // assignment copies the value
                // both variable have independent values

    cout << "Previous values: " << a  << " " << b << endl;
    a++;
    b--;
    cout << "Newest values:   " << a  << " " << b << endl;


    return 0;
}