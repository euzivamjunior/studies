#include <iostream>
using namespace std;

// referência: https://docs.microsoft.com/pt-br/cpp/cpp/references-cpp?view=vs-2019
int main () {
    int a = 10;
    cout << a << "\t" << &a << endl; //&a memory adress a var

    string name = "Paul";
    cout << name << "\t" << &name << endl; //&name memory address name
    return 0;
}