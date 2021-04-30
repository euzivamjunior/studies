#include <iostream>
using namespace std;


void incCopy(int value) {
    value++;
    value++;
    value++;
}

void incRef(int& value) {
    value++;
    value++;
    value++;
}


int main() {
    int x = 1;
    cout << x << endl;

    incCopy(x);
    cout << x << endl;

    incRef(x);
    cout << x << endl;

    return 0;
}