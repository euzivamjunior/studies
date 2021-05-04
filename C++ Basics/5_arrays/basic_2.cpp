#include <iostream>
using namespace std;

int main() {
    string names[5] = {"Hanna", "Peter", "Mary", "Mike", "James"};
    names[1] = "John";

    // array size
    int size = sizeof names / sizeof names[0];
    for(int i = 0; i < size; i++) {
        cout << names[i] << " ";
    }

    return 0;
}