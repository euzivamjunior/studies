#include <iostream>
using namespace std;

class Student{
    private:
    int sr;
    string name;

    public:
    Student();
    Student(int r, string n);
    int get_sr();
    string get_name();
};