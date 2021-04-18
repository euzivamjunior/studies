#include <iostream>
#include <student.h>

struct Node{
    // Student object element
    Student student;
    // left_child node pointer
    Node* left_child;
    // right_child node pointer
    Node* right_child;
    // node balance factor
    int balance_factor;

};

class AVLTree{
    private:
    // root: first(top) node of the tree
    Node* root;

    public:
    // Constructor
    AVLTree();
    // Destructor
    ~AVLTree();
    // delete all tree
    void delete_tree(Node* current_node);
    // get the root node of the tree
    Node* get_root();
    // is empty?
    bool is_empty();
    // is full? (there's no memory available?)
    bool is_full();
    // insert new Student element (new node)
    void insert(Student student);
    // remove Student element
    void remove(Student student);
    // Node*& current_node: (Node by reference) pointer to the current node,
    // not the current node indeed.
    void remove_search(Student student, Node*& current_node, bool& shrink);
    // delete node
    void delete_node(Node*& current_node, bool& shrink);
    // (Student object by reference)
    void get_successor(Student& student_successor, Node* temp_node);
    // search by student element
    void search(Student& student, bool& found_element);
    // pre-order traversal print tree
    void print_pre_order(Node* current_node);
    // in-order traversal print tree
    void print_in_order(Node* current_node);
    // pos-order traversal print tree
    void print_pos_order(Node* current_node);

    // AVL TREE - NEW METHODS

    // right simple node rotation
    void right_rotation(Node*& tree);
    // left simple node rotation
    void left_rotation(Node*& tree);
    // double rotation (left->right)
    void left_right_rotation(Node*& tree);
    // double rotation (right->left)
    void right_left_rotation(Node*& tree);
    // make node rotation
    void make_rotation(Node*& tree);
    // insertion function by recursive calls
    void recursive_insertion(Node*& current_node, Student student, bool& grow);
};
