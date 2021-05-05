#include <iostream>
using namespace std;

int main() {
    string names[] = {"Hanna", "Peter", "Marry", "Mike", "James"};

    for(int i = 0; i < 5; i++) {
        cout << names[i] << " ";
    }

    cout << "\nForeach...\n";

    for(string s: names) {
        cout << s << " ";
    }

    return 0;
}