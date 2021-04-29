# include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    // argc: number of arguments
    // argv: store arguments
    cout << "Number of arguments: " << argc << endl;
    cout << "first argument: " << argv[0] << endl;
    if(argc >= 2) {
        cout << argv[1] << endl;
    }
    return 0;
}
