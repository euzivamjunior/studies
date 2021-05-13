#include <iostream>
using namespace std;

class Person {
public:
    string name;
    // Constructor
    Person(string name) : name(name) {
        cout << "Hello! My name is " << name << endl;
    }
    // Destructor
    ~Person() {
        cout << name << " saying goodbye!" << endl;
    }
};

void changePerson(Person& p) {
    p.name += " Parker";
}

Person* createPerson() {
    Person* p = new Person("Peter");
    return p;
}

int main() {
    // new operator allocates memory on the heap
    // and calls constructor
    Person* person1 = new Person("Aunt May Parker");
    // delete operator frees memory
    // and calls destructor
    delete person1;

    // Manually allocate and frees memory
    Person* person2 = (Person*) malloc(sizeof(Person));
    free(person2);

    Person* person3 = createPerson();
    // In this case we can change person3 even after
    // the end of his scope, because it's allocation
    // was made in heap memomry.
    changePerson(*person3);
    cout << person3->name << endl;
    delete person3;

    return 0;
}