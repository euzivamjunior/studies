#include <iostream>
using namespace std;

class Person {
public:
    string name;
    Person(string name) : name(name) {
        cout << "Hello! My name is " << name << endl;
    }
    ~Person() {
        cout << name << " saying goodbye" << endl;
    }
};

Person* createPerson() {
    Person p("Hanna");
    return &p;
}

int main() {
    //Person object pointer
    Person* pp1;

    {
        Person p1("Peter");
        pp1 = &p1;
    }
    /*
        As we can see bellow, we have an false existing
        object. the p1 object was destroyed at the end of
        the scope above, therefore your value is still
        accessible by the pointer. But this is not a 
        guarantee that it should be work since this memory
        region is free to alocate another data.
    */
    cout << "pp1 " << pp1->name << endl;

    Person* pp2 = createPerson();
    /*
        In the case below, the value of the pp2 pointer
        explicitly doesn't exist (or is an trash value),
        since it's current object p was destroyed in the
        end of createPerson() function scope.
    */
    cout << "pp2 " << pp2->name << endl;

    cout << "End of code!" << endl;

    return 0;
}