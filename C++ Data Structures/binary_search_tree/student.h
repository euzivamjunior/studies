#include <iostream>
/*
    the namespace std is required to use string var
    if want to avoid this, then use std::string to
    declare a variable.
*/
using namespace std;

class Student{
    private:
    int SR;
    string name;

    public:
    Student();
    Student(int s, string n);
    string get_name();
    int get_sr();
};