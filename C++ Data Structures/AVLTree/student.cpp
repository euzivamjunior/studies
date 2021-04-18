#include "student.h"

using namespace std;

    Student::Student(){
        SR = -1;
        name = " ";
    }
    Student::Student(int s, string n){
        SR = s;
        name = n;
    }
    string Student::get_name(){
        return name;
    }
    int Student::get_sr(){
        return SR;
    }