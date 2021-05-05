#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        // matriz a[i][j]
        {1, 2, 3}, //1
        {4, 5, 6}, //3
        {7, 8, 9}  //2
    //j: 1  2  3
    };

    cout << matrix[1][2] << endl;
    matrix[1][2] = 16;
    cout << matrix[1][2] << endl;

    // loop over a 2-dimensional array
    for(auto const &row: matrix) {
        for(auto const &column: row) {
            cout << column << " ";
        }
    }

    return 0;
}