#include <iostream>
using namespace std;

int main () {
    int firstNumber;
    int secondNumber;
    int thirdNumber;

    cout << "Enter the first number: ";
    cin >> firstNumber;

    cout << "Enter the second number: ";
    cin >> secondNumber;

    cout << "Enter the third number: ";
    cin >> thirdNumber;

    int greaterNumber = firstNumber;

    if (secondNumber > greaterNumber)
        greaterNumber = secondNumber;

    if (thirdNumber > greaterNumber)
        greaterNumber = thirdNumber;

    cout << "The greater number is: " << greaterNumber << endl;

    return 0;
}