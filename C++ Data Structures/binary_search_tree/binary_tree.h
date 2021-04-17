#include <iostream>
#include "student.h"

struct Node{
    // object Student
    Student student;
    // pointer to the left child of the node
    Node* left_child;
    // pointer to the rich child of the node
    Node* right_child;
};

class BinarySearchTree{
    private:
    Node* root;

    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void delete_tree(Node* current_node);
    // get root pointer
    Node* get_root();
    bool is_empty();
    bool is_full();
    void insert(Student student);
    void remove(Student student);
    // Node*& current_node: (Node by reference) pointer to the current node,
    // not the current node indeed.
    void remove_search(Student student, Node*& current_node);
    void delete_node(Node*& current_node);
    // (Student object by reference)
    void get_successor(Student& student_successor, Node* temp_node);
    void search(Student& student, bool& found_element);
    void print_pre_order(Node* current_node);
    void print_in_order(Node* current_node);
    void print_pos_order(Node* current_node);
};