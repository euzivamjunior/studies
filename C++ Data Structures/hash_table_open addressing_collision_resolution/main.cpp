#include <iostream>
#include "hash.h"

using namespace std;

int main(){
    int vector_size, max_items;

    cout << "Script - Hash Generator!" << endl;

    cout << "Input the Hash size desired!: ";
    cin >> vector_size;

    cout << "Type the max number of elements: ";
    cin >> max_items;

    while (vector_size <= max_items){
        cout << "The load factor cannot be greater than or equal to 1" << endl;
        cout << "Please, type an max number elements smaller than "
             << "the Hash Size = " << vector_size << ": ";
        cin >> max_items; 
    }

    cout << "THe load factor is: " 
         << (float)max_items / (float)vector_size << endl;

    Hash student_hash(vector_size, max_items);
    int control;
    int sr;
    string name;
    bool search;

    do{
        cout << endl;
        cout << "Type 0 to stop the exit the script!" << endl;
        cout << "Type 1 to insert an element!" << endl;
        cout << "Type 2 to remove an element!" << endl;
        cout << "Type 3 to search by an element!" << endl;
        cout << "Type 4 to print the hash table elements" << endl;
        cout << "Your choice: ";
        cin >> control;

        if (control == 1){
            cout << "Type the Student School Registry: ";
            cin >> sr;

            cout << "Type the Student Name: ";
            cin >> name;

            Student student(sr, name);
            // insert student object on in the hash
            student_hash.push(student);
        } else if (control == 2){
            cout << "Type the Student School Registry: ";
            cin >> sr;

            Student student(sr, " ");
            // delete the student object from the hash
            student_hash.to_delete(student);
        } else if (control == 3){
            cout << "Type the Student School Registry: ";
            cin >> sr;

            Student student(sr, " ");
            // search for student by SR number
            student_hash.search(student, search);
            // if there are this student on the hash, then
            if (search){
                cout << "Student finded:" << endl;
                cout << "School Registry: " << student.get_sr();
                cout << "\tName: " << student.get_name() << endl;
            } else {
                cout << "Student not found!" << endl;
            }
        } else if (control == 4){
            student_hash.print();
        }

    } while (control != 0);

    return 0;
}