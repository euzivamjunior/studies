#include <iostream>
#include "binary_tree.h"

using namespace std;

int main(){
    BinarySearchTree student_tree;
    int control, sr, traversal_order;
    string name;
    bool search = false;

    do{
        cout << endl;
        cout << "Type 0 to stop the exit the script!" << endl;
        cout << "Type 1 to insert an element!" << endl;
        cout << "Type 2 to remove an element!" << endl;
        cout << "Type 3 to search by an element!" << endl;
        cout << "Type 4 to print the tree elements" << endl;
        cout << "Your choice: ";
        cin >> control;

        if (control == 1){
            cout << "Type the Student School Registry: ";
            cin >> sr;

            cout << "Type the Student Name: ";
            cin >> name;

            Student student(sr, name);
            if (student_tree.is_full()){
                cout << "There's no memory available" << endl;
                cout << "The new Student can't be inserted" << endl;
            } else{
                // insert student object on in the hash
                student_tree.insert(student);
            }
        } else if (control == 2){
            cout << "Type the Student School Registry: ";
            cin >> sr;

            Student student(sr, " ");
            // delete the student object from the hash
            student_tree.remove(student);
        } else if (control == 3){
            cout << "Type the Student School Registry: ";
            cin >> sr;

            Student student(sr, " ");
            // search for student by SR number
            student_tree.search(student, search);
            // if there are this student on the hash, then
            if (search){
                cout << "Student found:" << endl;
                cout << "School Registry: " << student.get_sr();
                cout << "\tName: " << student.get_name() << endl;
            } else {
                cout << "Student not found!" << endl;
            }
        } else if (control == 4){
            cout << "Type 1 for print in pre-order traversal" << endl;
            cout << "Type 2 for print in in-order traversal" << endl;
            cout << "Type 3 for print in pos-order traversal" << endl;
            cout << "Your choice: ";
            cin >> traversal_order;

            if (traversal_order == 1){
                student_tree.print_pre_order(student_tree.get_root());

            } else if (traversal_order == 2){
                student_tree.print_in_order(student_tree.get_root());
            } else{
                student_tree.print_pos_order(student_tree.get_root());
            }
        }

    } while(control != 0);

    return 0;
}