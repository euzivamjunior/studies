#include <iostream>
using namespace std;

int main () {
    int number = 0;
    int total = 0;
    int qty = 0;

    for(;number != -1;) {
        cout << "Enter a number or -1 to finish: ";
        cin >> number;

        if(number != -1) {
            total += number;
            qty++;
        }
    }

    // cast || total int to double
    double avg = (double) total / qty;
    cout << "The average is: " << avg << endl;

    /*
    // infinite for loop
    for(;;) {
        cout << "for...";
    }
    */

    return 0;
} 