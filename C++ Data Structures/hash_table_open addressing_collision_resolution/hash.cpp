#include <iostream>
#include "hash.h"

using namespace std;
    // define hash_function
    int Hash::hash_function(Student student){
        return (student.get_sr() % max_positions);
    }
    // constructor
    Hash::Hash(int vector_size, int max){
        number_items = 0;
        max_items = max;
        max_positions = vector_size;
        structure = new Student[vector_size];
    }
    // destructor
    Hash::~Hash(){
        delete [] structure;
    }
    // is full?
    bool Hash::is_full(){
        return (number_items == max_items);
    }
    // get lenght (number of itens in the hash table)
    int Hash::get_length(){
        return (number_items);
    }
    // insert student in the hash
    void Hash::push(Student student){
        if (is_full()){
            cout << "The Hash is full" << endl;
            cout << "The new Student can't be inserted" << endl;
        } else{
            // get local hash by computing hash function
            int local = hash_function(student);
            /*
                while strucure[local] has SR > 0 (i.e. there's already
                have an element stored in this position) keep going to
                the next index hash, until there's an local empty or
                available.
            */
            while (structure[local].get_sr() > 0){
                // If the local index becomes greater than max index of
                // the hash, then returns to search by the first index
                local = (local + 1) % max_positions;
            }
            // store the student object
            structure[local] = student;
            // increment number_itens
            number_items++;
        }
    }
    void Hash::to_delete(Student student){
        // get local hash by computing hash function
        int local = hash_function(student);
        /*
            While the structure[local].getsr() ins't -1 (empty), keep going
            to search the student element to delete.
            If while reachs an structure[local].get_sr() == -1, then there's
            no element to be deleted.
        */
        bool found_element = false;
        while (structure[local].get_sr() != -1){
            /*
                If local SR is equal to SR student, then remove the element
                from the hash table, and mark the local as available 
                Student(-2, " "), decrement number_items and break the loop.
            */
            if (structure[local].get_sr() == student.get_sr()){
                cout << "Element Removed!" << endl;
                structure[local] = Student(-2, " ");
                number_items--;
                found_element = true;
                break;
            }
            local = (local + 1) % max_positions;
        }
        // if found_element is false, then the element wasn't found.
        if (!found_element){
            cout << "The element was not found" << endl;
            cout << "No elements have been removed" << endl;
        }
    }
    void Hash::search(Student& student, bool& search_result){
        // get the local to search the current required student
        int local = hash_function(student);
        search_result = false;
        /*
            While the local SR ins't -1 (empty), keep going to search by 
            the student element. 
            If while reachs an  structure[local].get_sr() == -1, then the 
            element was not found into the hash.
        */
        while (structure[local].get_sr() != -1){
            if (structure[local].get_sr() == student.get_sr()){
                search_result = true;
                /*
                The search for the student is made by the SR info. if
                this student is finded in the Hash table, then the input 
                Student object has all your values updated by the the 
                object stored in the hash, thus, the current student
                object of the search is completed with the remaining
                informations values, like name.
                */
                student = structure[local];
                break;
            }
            local = (local++) % max_positions;
        }
    }
    void Hash::print(){
        cout << "Hash Table (Hash Map)" << endl;
        // iterate in the hash table
        for (int index=0; index<max_positions; index++){
            /*
                print values for each hash position that student object
                has SR > 0. (i.e. the index isn't an empty or available
                position, but a relevant stored element.
            */
            if (structure[index].get_sr() > 0){
                cout << "index " << index;
                cout<< "\tSchool Registry: " << structure[index].get_sr();
                cout << "\tName: " << structure[index].get_name() << endl;
            }
        }
    }