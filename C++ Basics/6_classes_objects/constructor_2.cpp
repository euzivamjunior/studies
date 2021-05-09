#include <iostream>
using namespace std;

class User {
public:
    string name;
    string email;


    // _Overload of Constructors
    // Default Constructor
    User() {}
    // Another Constructor
    User(string pname, string pemail) {
        name = pname;
        email = pemail;
    }

    string toString() {
        return name + " [" + email + "]";
    }
};

int main() {
    User user1;
    user1.name = "Peter Johnson";
    user1.email = "peter.john.123@zymail.com";

    User user2("Marry M.", "mym@foo.com");
    // The same as above || Explicity Constructor
    //User user2 = User("Marry M.", "mym@foo.com");

    cout << user1.toString() << endl;
    cout << user2.toString() << endl;

    return 0;
}