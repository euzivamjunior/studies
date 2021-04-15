#include "student.h"

    Student::Student(){
        sr = -1;
        name = " ";
    }
    Student::Student(int r, string n){
        sr = r;
        name = n;
    }
    int Student::get_sr(){
        return sr;
    }
    string Student::get_name(){
        return name;
    }