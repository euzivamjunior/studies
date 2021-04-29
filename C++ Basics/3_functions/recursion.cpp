#include <iostream>
using namespace std;

/*
int factorial(int n) {
    int total =1;
    for(int i = 2; i<= n; n++) {
        total *= i;
    }
    
    return total;
}
*/

// recursion function
int factorial(int n) {
    if(n <= 0) return -1; // error - unexpected number
    if(n == 1) return 1;

    return n * factorial(n-1);
}


int main() {
    cout << factorial(3) << endl;
    cout << factorial(4) << endl;
    cout << factorial(5) << endl;

    return 0;
}