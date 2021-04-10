#include <iostream>
using namespace std;

int main () {

    for(int i = 0; i < 10; i++) {
        if(i % 2 == 0) {
            // jumpt to the next iteration
            continue;
        }else if(i == 5) {
            // quit the loop
            break;
        }
        cout << i << " ";
    }

    cout << "end" << endl;

    return 0;
}