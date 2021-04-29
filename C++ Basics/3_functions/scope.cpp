#include <iostream>
using namespace std;

// global variable: can be accessed inside functions
int globalVar = 10;

void func3() {
    // global variable
    globalVar += 10;

    // once a var is declared inside function, the var 
    // is turned into a local variable whithout modify 
    //the global variable
    int globalVar;
    globalVar = 5;

    cout << "exec #03... " << globalVar << endl;
}


void func2() {
    func3();
    cout << "exec #02..." << endl;
}


void func1() {
    func2();
    cout << "exec #01..." << endl;
}


int main() {
    func1();
    cout << "exec #main..." << endl << endl;
    cout << "Global Var: " << globalVar << endl;

    {   // the variables inside this block code
        // can't be accessed outside of scope
        int varBlock = -1;
        cout << varBlock << endl;
    }
    //varBlock can't be accessed:
    //cout << varBlock << endl;

    return 0;
}

/*
Stack *Execution
--------------------------------------------------------------------------->
                             *func3()
                   *func2()   func2()  *func2()
         *func1()   func1()   func1()   func1()  *func1()
*main()   main()    main()    main()    main()    main()   *main()  *end_run
*/