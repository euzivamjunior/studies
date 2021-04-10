#include <iostream>
using namespace std;

int main (){
    // const: imutable variable value
    const double PI = 3.1415;
    double radius;
    double area;

    cout << "Enter radius: ";
    cin >> radius; 
    area = PI * radius * radius;

    cout << "Area is: " << area;
    return 0;
}