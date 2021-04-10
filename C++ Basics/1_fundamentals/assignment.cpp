#include <iostream>
using namespace std;

main(){
    int x;
    cout << "Enter the initial value: ";
    cin >> x;

    x += 10;
    cout << x << endl;

    x -= 9;
    cout << x << endl;

    x *= 8;
    cout << x << endl;

    x /= 7;
    cout << x << endl;

    x %= 6;
    cout << x << endl;

    return 0;
}