#include <iostream>
using namespace std;

int main () {
    bool sunny = true;
    // expression_bool(T/F) ? T : F
    string result = sunny ? ":)" : ":(";
    cout << result << endl;

    double balance = 1234.56;
    double value;
    cout << "Enter the value: ";
    cin >> value;

    char creditOrDebt;
    cout << "Credit (c) / Debt (d): ";
    cin >> creditOrDebt;

    cout << "Balance [Before]: " << balance << endl;
    
    // credit or debt value based on "creditOrDebt == 'c'" condition
    balance += creditOrDebt == 'c' ? value : -value;

    cout << "Balance [After]: " << balance << endl;

    return 0;
}