#include <iostream>
using namespace std;

int main () {
    int arr[] = {47, 33, 72, 13, 88};

    // It's not possible to pointer to an entire array, so
    // it needed to pointer to a single element
    int* p1 = &arr[0];
    cout << p1 << "\t" << *p1 << endl << endl;

    //increment pointer by nByteSize variable type | int case: 4Bytes
    p1++;
    cout << p1 << "\t" << *p1 << endl << endl;

    // [0] same as *
    cout << p1[0] << "\t" << p1[1] << endl << endl;

    // change array value by pointer
    p1--;
    p1[0] = 62;
    cout << p1[0] << "\t" << arr[0] << endl;



    return 0;
}