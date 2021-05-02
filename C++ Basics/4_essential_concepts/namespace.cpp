#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b + 10;
}

/*
    NAMESPACE
    --------------------------------------------------------
    In computing, a namespace is a set of signs (names) that 
    are used to identify and refer to objects of various 
    kinds. A namespace ensures that all of a given set of 
    objects have unique names so that they can be easily 
    identified.

    Namespace can help to avoid conflit objects name.

*/

namespace calc {
    int add(int a, int b) {
        return a + b + 20;
    }
}

int main() {
    cout << add(10, 20) << endl;
    cout << calc::add(10, 20) << endl;

    return 0;
}