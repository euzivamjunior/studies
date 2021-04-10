#include <iostream>
using namespace std;

int main () {
    double finalGrade;
    cout << "Enter the final grade: ";
    cin >> finalGrade;

    // if for single statement
    if(finalGrade >= 7)
        cout << "The final grade is greater than or equal to 7" << endl;

    // if for block of code
    if(finalGrade >= 7) {
        cout << "Excelent grade." << endl;
        cout << "Congratulations!" << endl;
    }

    return 0;
}