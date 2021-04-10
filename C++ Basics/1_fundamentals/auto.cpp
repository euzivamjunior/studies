#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    int a = 1;
    double b = 1.2;
    bool c = false;

    // i: inteiro || d: double || b: bool
    cout << typeid(a).name() << endl
         << typeid(b).name() << endl
         << typeid(c).name() << endl << endl;

    // type inference
    auto aInference = 1;
    auto bInference = 1.2;
    auto cInference = false;

    cout << typeid(aInference).name() << endl
         << typeid(bInference).name() << endl
         << typeid(cInference).name() << endl;

    return 0;
}