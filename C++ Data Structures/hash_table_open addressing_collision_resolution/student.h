#include <iostream>
/*
    the namespace std is required to use string var
    if want to avoid this, then use std::string to
    declare a variable without require to declare
    using namespace std
*/
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