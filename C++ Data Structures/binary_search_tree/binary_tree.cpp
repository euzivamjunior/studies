#include <iostream>
#include <cstddef>
#include "binary_tree.h"

    // Constructor function
    BinarySearchTree::BinarySearchTree(){
        root = nullptr;
    }
    // Destructor function
    BinarySearchTree::~BinarySearchTree(){

    }
    void BinarySearchTree::delete_tree(Node* current_node){

    }
    // get root pointer
    Node* BinarySearchTree::get_root(){
        return root;
    }
    // is empty?
    bool BinarySearchTree::is_empty(){
        return (root == nullptr);
    }
    // the computer memory is full?
    bool BinarySearchTree::is_full(){
        try{
            Node* temp_node = new Node;
            delete temp_node;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }
    // insert an element in the tree
    void BinarySearchTree::insert(Student student){
        if (is_full()){
            cout << "There's no memory available to insert a new element" << endl;
            cout << "The element couldn't be inserted" << endl;
        } else{
            // create a new Node object
            Node* new_node = new Node;
            new_node->student = student;
            new_node->left_child = nullptr;
            new_node->right_child = nullptr;

            // if the tree is empty, then the new Node becomes the root Node.
            if (is_empty()){
                root = new_node;
            // if the tree isn't empty, then search a new a position.
            } else{
                // temporary Node (current Node) to go through the tree.
                Node* temp_node = root;
                /*
                    The element location is given by the following rule:

                    Starting in the root node, while current node is not null, 
                    checks if the new Node value is smaller or greter than the 
                    current root node. 

                    IF SMALLER: 
                    check if there are an next node in the left, if not, then the 
                    new node becomes this left Node. if already have an Node, the
                    temp Node moves to the left Node and make the same check about 
                    the new "NODE VALUE be SMALLER or GREATER than the temp_Node", 
                    and so on, until to find an empty child (left or right) node.

                    IF GREATER:
                    apply the same rule above by the node on the right.

                */
                while (temp_node != nullptr){
                    // if new value is smaller than the current node value
                    if (student.get_sr() < temp_node->student.get_sr()){
                        /*
                            if (there's no child on the left), then new node 
                            becomes the left child of the current node.
                            else: current node move to the left node;
                        */
                        if (temp_node->left_child == nullptr){
                            temp_node->left_child = new_node;
                            break;
                        } else{
                            temp_node = temp_node->left_child;
                        }
                    // else: the new value is greater than current node value
                    } else{
                        /*
                            if (there's no child on the right), then new node 
                            becomes the right child of the current node.
                            else: current node move to the right node;
                        */
                        if (temp_node->right_child == nullptr){
                            temp_node->right_child = new_node;
                            break;
                        } else{
                            temp_node = temp_node->right_child;
                        }
                    }
                }
            }
        }
    }
    void BinarySearchTree::remove(Student student){

    }
    void BinarySearchTree::search(Student& student, bool& busca){

    }
    void BinarySearchTree::print_pre_order(Node* current_node){

    }
    void BinarySearchTree::print_in_order(Node* current_node){

    }
    void BinarySearchTree::print_pos_order(Node* current_node){

    }