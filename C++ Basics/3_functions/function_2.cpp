#include <iostream>
#include "function_2.h" // include header
using namespace std;

/*
    To avoid compilation error for functions bellow the the
    main function, we can use Function prototype, or use
    header file, where function is defined. Or simply put
    the function above on main function.

    // Function prototype
    // void log(int number, bool newLine);

    // Header
    #include "function_2.h"
*/


int main () {
    // the newLine default value was defined on the header
    // newLine default = true
    log(3);
    log(4);
    log(5);

    log(6, false);
    log(7, false);
    log(8, false);

    return 0;
}


void log(int number, bool newLine) {
    cout << "Number: " << number;
    newLine ? cout << endl : cout << " ";
}