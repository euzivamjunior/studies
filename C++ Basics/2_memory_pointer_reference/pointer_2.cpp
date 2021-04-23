#include <iostream>
using namespace std;

int main () {
    /*
        A pointer is a special variable type, that stores an memory 
        address. A pointer can have the value that is an invalid 
        address. The nullptr macro is defined in the stdlib.h 
        interface and its value is 0 (zero) in most computers.

        The empty pointer points to any address of memory. that 
        contains 'garbage' or zero value ... (indefined)

        So, to avoid garbage with indefined (random) memory address, 
        the undefined pointer is initialized with nullptr (NULL)

        https://www.ime.usp.br/~pf/algoritmos/aulas/pont.html
        http://wiki.icmc.usp.br/images/e/e6/Aula2-Ponteiros_2010.pdf
    */
    int* p1; // empty pointer
    int* p2 = nullptr; // null pointer

    cout << p1 << endl;
    cout << p2 << endl;

    int x = 5;
    int y = 10;

    p1 = &x;
    cout << p1 << "\t" << *p1 << endl;

    p1 = &y;
    cout << p1 << "\t" << *p1 << endl;

    p2 = p1;
    cout << p2 << "\t" << *p2 << endl;

    return 0;
}