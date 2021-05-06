#include <iostream>
using namespace std;

int main() {
    string names[] = {"Hanna", "Peter", "Marry", "Mike", "James"};

    for(int i = 0; i < 5; i++) {
        cout << names[i] << " ";
    }

    cout << "\nForeach #01 (Copy)...\n";
    for(string s: names) {
        s.append("!!!!!");
        cout << s << " ";
    }
    cout << endl << names[0] << endl;

    cout << "\nForeach #01 (Reference)...\n";
    for(string &s: names) {
        s.append("!!!!!");
        cout << s << " ";
    }
    cout << endl << names[0] << endl;

    cout << "\nForeach #03 Auto Type...\n";
    for(auto &s: names) {
        s.append("!!!!!");
        cout << s << " ";
    }
    cout << endl << names[0] << endl;

    cout << "\nForeach #04 (Reference Constant)...\n";
    for(auto const &s: names) {
        /*
        s.append("!!!!!"); s as const can't be changed

        This way can be more quickly than by copy and
        assured that the original value will not be changed
        */
        cout << s << " ";
    }
    cout << endl << names[0] << endl;

    return 0;
}