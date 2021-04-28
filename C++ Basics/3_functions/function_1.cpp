#include <iostream>
using namespace std;

// void function: return nothing
// this example: there's nothing parameters
void sayHello() {
    cout << "Hello!\n";
}

// this example: there are parameters (string name)
void sayHelloTo(string name) {
    cout << "Hello " << name << "!" << endl;
}

// string function: return string
string returnHi() {
    return "Hi";
}


string returnHiTo(string name) {
    return "Hi " + name + "!";
}


int main() {
    sayHello();

    sayHelloTo("Peter");
    sayHelloTo("Hanna");

    string result = returnHi();
    result.append("!");
    cout << result << endl;

    cout << returnHi() << endl;

    cout << returnHiTo("Mike") << endl;

    return 0;
}