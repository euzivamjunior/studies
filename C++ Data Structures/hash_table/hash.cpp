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
        // get local hash by computing hash function
        int local = hash_function(student);
        // store the student object
        structure[local] = student;
        // increment number_itens
        number_items++;
    }
    void Hash::to_delete(Student student){
        // get local hash by computing hash function
        int local = hash_function(student);
        // if sr is different of -1, then, there are an element
        // in the hash on 'local' position
        if (structure[local].get_sr() != -1){
            // change the local hash with an object containing default 
            // empty values.
            structure[local] = Student(-1, " ");
            number_items--;
        }
    }
    void Hash::search(Student& student, bool& search_result){
        // get the local to search the current required student
        int local = hash_function(student);
        // get the student from the local above
        Student aux = structure[local];
        /*
            if the SR from the required student != current stored SR 
            values in the Hash, then return false, otherwise update
            object informations, then return true.
        */
        if (student.get_sr() != aux.get_sr()){
            search_result = false;
        } else{
            search_result = true;
            /*
                The search for the student is made by the SR info. if
                this student is finded in the Hash table, then the input 
                Student object has all your values updated by the the 
                object stored in the hash, thus, the current student
                object of the search is completed with the remaining
                informations values, like name.
            */
            student = aux;
        }
    }
    void Hash::print(){
        cout << "Hash Table (Hash Map)" << endl;
        // iterate in the hash table
        for (int index=0; index<max_positions; index++){
            // print values for each hash position that student object
            // has SR != -1.
            if (structure[index].get_sr() != -1){
                cout << index << ":" << structure[index].get_sr();
                cout << " " << structure[index].get_name() << endl;
            }
        }
    }