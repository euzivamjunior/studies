#include <iostream>
using namespace std;


// FUNCTION AS PARAMETER TO ANOTHER FUNCTION --------------||
//
// first param ----------------------------------------------
// int (*func)(int, int): pointer function as param, where...
// int: type function return || (*func): function pointer
// (int, int): params for pointer function
//
// second param ---------------------------------------------
// int c: just an integer 
//
// third param ----------------------------------------------
// int d: an integer value
int exec(int (*func)(int, int), int c, int d) {

    // return: (returned value of pointer function)(params)
    return (*func)(c, d);
}

// to simplify the pointer function passed as parameter into
// the above function, we can use typedef to assign an easier
// name.
using binaryop = int (*)(int, int);

// execSimplified() now is equal to exec()
int execSimplified(binaryop func, int c, int d) {
    return (*func)(c, d);
}



int add(int a, int b) {
    return a + b;
}


int subtract(int a, int b) {
    return a - b;
}


int min(int a, int b) {
    return a < b ? a : b;
}


int main() {
    cout << exec(add, 33, 44) << endl;
    cout << exec(subtract, 7, 2) << endl;
    cout << exec(min, 11, 54) << endl << endl;

    cout << execSimplified(add, 33, 44) << endl;
    cout << execSimplified(subtract, 7, 2) << endl;
    cout << execSimplified(min, 11, 54) << endl << endl;

    return 0;
}