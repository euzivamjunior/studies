#include <iostream>
using namespace std;

int main () {
    // binary and infix
    cout << 2 + 2 << endl;
    cout << 2 - 2 << endl;
    cout << 2 * 2 << endl;
    cout << 2 / 2 << endl;
    cout << 10 % 3 << endl;
    cout << 10 + 3 * 7 << endl;
    cout << (10 + 3) * 7 << endl << endl;

    int x;
    int y;

    cout << "Enter an integer number: ";
    cin >> x;

    cout << "Enter another integer number: ";
    cin >> y;

    cout << "Results: " << endl;
    cout << x + y << endl;
    cout << x - y << endl;
    cout << x * y << endl;
    cout << x / y << endl;
    cout << x % y << endl;

    return 0;
}