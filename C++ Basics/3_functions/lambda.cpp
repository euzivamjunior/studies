#include <iostream>
using namespace std;

// lambda function or anonymous function, this is a shorter way 
// to define a function with no name, so is needed to store the 
// return value into a variable.
//
// type variableName = [](input params) -> type {return param;};
//the return type can be also auto by omitting type:
// type variableName = [](input params) {return param;};

auto add = [](int x, int y) -> int { return x + y; };
auto subt = [](int x, int y) { return x - y; };


// lambda function also can be used as pointer function param.
using binaryop = int (*)(int, int);

int execSimplified(binaryop func, int a, int b) {
    return (*func)(a, b);
}


int main() {
    cout << add(10, 20) << endl;
    cout << subt(20, 26) << endl << endl;

    cout << execSimplified(add, 10, 20) << endl;
    cout << execSimplified(subt, 20, 26) << endl << endl;

    // lambda can also be used directly as param without previous
    // definition.
    cout << execSimplified([](int x, int y) { return x * y; }, 7, 9);

    return 0;
}