#include <iostream>
using namespace std;

// TIPO STRING: http://cplusplus.com/reference/string/string/
int main(){
    // string std namespace
    std::string firstString;

    // string with 'using namespace std'
    string title = "Mr. ";
    string name("John");
    string end(10, '!');

    cout << "String size: "<< name.size() << endl;
    cout << "Last char: " << name.back() << endl;
    cout << "n position char: " << name[1] << endl;
    cout << "n times string: " << end << endl;

    // string concatenation
    cout << "Concatenate title + name: "<< title + name << endl;
    name.append(" Titor"); // more efficient to concat
    name += "!";
    cout << "Append name: " << name << endl;

    return 0;
}