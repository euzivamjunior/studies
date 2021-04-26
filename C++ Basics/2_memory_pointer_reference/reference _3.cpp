#include <iostream>
using namespace std;

int main () {
    // It's not possible to have an empty reference
    //string& badRef;
    string greeting = "Hi!";
    string& ref = greeting; // assignment by reference


    cout << greeting << "\t" << ref << endl;

    string name = "Peter";
    
    // It's not possible to reassign a reference
    ref = name; // assignment by copy

    /*
    Once reference is created, there's no way to change
    the reference to another memory address (variable address)
    */

    cout << name << "\t" << ref << "\t" << greeting << endl;
    cout << &name << "\t" << &ref << "\t" << &greeting << endl;

    ref.append("!!!!!!!!!!!!!");

    cout << name << "\t" << ref << "\t" << greeting << endl;

    return 0;
}