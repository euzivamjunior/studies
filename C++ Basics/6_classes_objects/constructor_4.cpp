#include <iostream>
using namespace std;

class Actor {
public:
    string name;
    string email;

    Actor(string name = "Anonymous", string email = "???")
        //: class_ attribute(constructor_parameter)
        : name(name), email(email) {}

    string toString() {
        return name + " [" + email + "]";
    }
};

int main() {
    Actor actor1;
    Actor actor2("Steve", "carell@office.com");
    // In the case bellow, braces {} can be used
    Actor actor3{"John", "krasinski@office.com"};
    Actor actor4("Carol");

    cout << actor1.toString() << endl;
    cout << actor2.toString() << endl;
    cout << actor3.toString() << endl;
    cout << actor4.toString() << endl;

    return 0;
}