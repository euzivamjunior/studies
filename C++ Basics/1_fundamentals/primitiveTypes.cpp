#include <iostream>
using namespace std;


// primitive types: https://pt.cppreference.com/w/cpp/language/types
//                  https://www.geeksforgeeks.org/c-data-types/
int main(){
    // bool: False = 0 | True != 0 --> True = 1
    cout << "\n-------------BOOL VALUES-------------" << endl;

    bool fistValue = 0;
    bool secondValue = 1;
    bool thirdValue = 157;
    bool fourthValue = -0.03;
    bool fifthValue = false;
    bool sixthValue = true;

    cout << "bool 0     = " << fistValue << endl;
    cout << "bool 1     = " << secondValue << endl;
    cout << "bool 157   = " << thirdValue << endl;
    cout << "bool -0.03 = " << fourthValue << endl;
    cout << "bool false = " << fifthValue << endl;
    cout << "bool true  = " << sixthValue << endl;

    // CHAR VALUES
    cout << "\n-------------CHAR VALUES-------------" << endl;

    char firstSymbol = '#';
    char secondSymbol('#');

    cout << firstSymbol << endl;
    cout << secondSymbol << endl;

    // INT VALUES
    cout << "\n--------------INT VALUES-------------" << endl;

    // DATATYPE MODIFIERS || short: small int naumber || unsigned: no signed number
    unsigned short int age = 31;
    long secondInt = 31;
    long long thirdInt = 31;

    cout << "Unsigned short int | Age: " << age << endl;
    cout << "Long int           | secondInt: " << secondInt << endl;
    cout << "Long long int      | thirdInt: " << thirdInt << endl;

    // FLOAT VALUES
    cout << "\n------------FLOAT VALUES------------" << endl;
    
    float pi = 3.14; // 32 bits - single precision floating point type
    double PI = 3.141592; // 64 bits - double precision floating point type

    cout << "Float value  = " << pi << endl;
    cout << "Double value = " << PI << endl;

    // TYPE BYTE SIZE
    cout << "\n--------------BYTE SIZE-------------" << endl;

    cout << "Size of bool          = "<< sizeof(bool) << " byte" << endl;
    cout << "Size of char          = "<< sizeof(char) << " byte" << endl;
    cout << "Size of wchar_t       = "<< sizeof(wchar_t) << " byte" << endl;
    cout << "Size of int           = "<< sizeof(int) << " byte" << endl;
    cout << "Size of short int     = "<< sizeof(short int) << " byte" << endl;
    cout << "Size of long int      = "<< sizeof(long int) << " byte" << endl;
    cout << "Size of long long int = "<< sizeof(long long int) << " byte" << endl;
    cout << "Size of float         = "<< sizeof(float) << " byte" << endl;
    cout << "Size of double        = "<< sizeof(double) << " byte" << endl;

    return 0;
}