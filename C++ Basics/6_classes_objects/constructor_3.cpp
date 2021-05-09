#include <iostream>
using namespace std;

class Actor {
public:
    string name;
    string email;

    // Call another constructor from a constructor
    Actor() : Actor("Anonymous") {}

    // default value definition: string email = "-"
    Actor(string name, string email = "???") {
        // (*this).name = name;
        // (*this).email = email;
        this->name = name;
        this->email = email;
    }

    string toString() {
        return name + " [" + email + "]";
    }
};

int main() {
    Actor actor1;
    Actor actor2("Steve", "carell@office.com");
    Actor actor3("Carol");

    cout << actor1.toString() << endl;
    cout << actor2.toString() << endl;
    cout << actor3.toString() << endl;

    return 0;
}