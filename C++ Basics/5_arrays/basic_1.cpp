#include <iostream>
using namespace std;

int main() {
    string names[5];
    names[0] = "Hanna";
    names[1] = "Peter";
    names[2] = "Mary";
    names[3] = "Mike";
    names[4] = "James";

    cout << names[0] << endl;
    cout << names[1] << endl;
    cout << names[2] << endl;
    cout << names[3] << endl;
    cout << names[4] << endl;

    /*
    INDEX OUT OF RANGE can be accessed in an array,
    but your value is garbage, since we don't know
    what is in. So this access have to be avoided
    */

    cout << names[5] << endl;

    return 0;
}