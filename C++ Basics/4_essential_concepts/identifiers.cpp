#include <iostream>
using namespace std;

/*
    OVERLOADING
    ------------------------------------------------------
    Overloading allows different methods (or functions) to 
    have the same name, but different signatures where the 
    signature can differ by the number of input parameters 
    or type of input parameters or both.

    The signature of the function is based on it's name
    and it's parameters (not only by it's name). This is
    why we can define functions with the same name, but
    with number of parameters and types differents.
*/
int add(int x, int y) {
    return x + y;
}

int add(int x, int y, int z) {
    return x + y + z;
}

double add(double x, int y) {
    return x + y + 1000;
}

double add(int x, double y) {
    return x + y + 2000;
}

int main() {
    cout << add(10, 20) << endl;
    cout << add(10, 20, 30) << endl;
    cout << add(10.0, 20) << endl;
    cout << add(10, 20.0) << endl;

    return 0;
}