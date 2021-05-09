#include <iostream>
using namespace std;

class Person {
public:
    string name;
    Person(string name) : name(name) {
        // message when an Person object is created
        cout << "Hello! My name is " << name << endl;
    }
    ~Person() {
        // message when an Person object is destroyed
        cout << name << " saying goodbye!" << endl;
    }
};

void createPerson() {
    Person p = {"John"};
}

int main() {
    Person p1("Peter");
    createPerson();

    /*
    OBJECTS ARE DESTROYED IN THE END OF SCOPE
    --------------------------------------------------------
    The object is destroyed in the end of an scope. So the 
    objects bellow (p2, p3, p4) will be destroyed before 
    the p1 object. Since them are inside an specific scope{}  

    The p1 object will be destroyed in the final of the
    main scope
    */

    {   
        Person p2{"Mary"};
        Person p3 = Person("May");
    }

    /*
    This pointer object is not associated with this scope
    therefore, at the end of scope it will not be destroyed.
    This behavior will be discussed in a future exercise.
    */
    Person* p0 = new Person("Test");

    cout << "End of code!" << endl;

    return 0;
}