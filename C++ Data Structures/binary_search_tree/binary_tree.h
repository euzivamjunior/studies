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
    void search(Student& student, bool& busca);
    void print_pre_order(Node* current_node);
    void print_in_order(Node* current_node);
    void print_pos_order(Node* current_node);
};