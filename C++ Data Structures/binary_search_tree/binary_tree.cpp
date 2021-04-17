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
        /*
            Try to create a new node, if succeed, then, there are memory available
            oterwise, the computer memory is full.
        */
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
        remove_search(student, root);
    }
    /*
        Node*& current_node: (Node by reference) pointer to the current node,
        not the current node indeed.

        This function runs recursively until find the searched element.
        i.e. when the SR student is equal to SR of the current_node.

        Search by the student element by using recursion.
        Starting by the root node (current node), if SR student is smaller than
        the SR current node, then call recursively the remove_search function
        with student object and the left child of the current node,
        if SR student is greater than SR current node, then call the same
        function with the student node and the right child of the current node,
        otherwise, the SR student and SR current node are equal, then call the
        delete_node() function.
    */
    void BinarySearchTree::remove_search(Student student, Node*& current_node){
        if (student.get_sr() < current_node->student.get_sr()){
            remove_search(student, current_node->left_child);
        } else if (student.get_sr() > current_node->student.get_sr()){
            remove_search(student, current_node->right_child);
        } else{
            delete_node(current_node);
        }
    }
    void BinarySearchTree::delete_node(Node*& current_node){
        Node* temp_node = current_node;
        /*
            IF the left child of the current node is null, then the current node pointer
            becomes the right child and the temp node is deleted (searched node to delete).
            this approach will works on the case on the current node has only the right 
            child, when the current_node becomes the pointer to the right child, and
            also works when there's no child on the node, because the right child is
            nullptr, so the current_node becomes the pointer to nullptr.

        */
        if (current_node->left_child == nullptr){
            current_node = current_node->right_child;
            delete temp_node;
        // similar to the rule above, the same rule is applied by the inverse (right) node.
        } else if (current_node->right_child == nullptr){
            current_node = current_node->left_child;
            delete_node;
        /*
            In this case the node have both right and left child, then in this case it
            needed to search by a succesor node of the current node that will becomes 
            the current node value. After this, the student_successor (now duclicate as 
            the current node as they have the same value) is deleted by the remove_search() 
            function.
        */
        } else{
            Student student_successor;
            get_successor(student_successor, current_node);
            current_node->student = student_successor;
            remove_search(student_successor, current_node->right_child);
        }
    }
    /*
        (Student object by reference, to enable changes by the delete_node() function).
        get_successor function runs by the following rule. moves the temp node to the right
        child, then keep moving to the left child until the left_child of the temp node
        becomes nullptr (i.e. there's no left-child), then the student_successor becomes
        the temp_node student object.
    */
    void BinarySearchTree::get_successor(Student& student_successor, Node* temp_node){
        temp_node = temp_node->right_child;
        while (temp_node->left_child != nullptr){
            temp_node = temp_node->left_child;
        }
        student_successor = temp_node->student;
    }
    void BinarySearchTree::search(Student& student, bool& found_element){
        found_element = false;
        // temporary Node (current Node) to go through the tree.
        Node* current_node = root;
        /*
            Search the element by the rule:
            Starting by the current Node as the root node, while current node is 
            not null, compares the student SR with the current Node SR, if the 
            student SR value was smaller than Node SR, then, current node 
            becomes the left-node, if the student SR is greater than the current
            Node SR, the the current Nodes becomes the right-node, otherwise the
            student SR is equal to current Node SR, then the element was found.

            The process described above runs until the current Node reach a
            nullptr (element not found), or current SR be equal to student SR
            (element found).

            If the element was found, than the student object (containing only
            SR information) becomes equal current element, which have the SR and
            name value.
        */
        while (current_node != nullptr){
            if (student.get_sr() < current_node->student.get_sr()){
                current_node = current_node->left_child;
            } else if (student.get_sr() > current_node->student.get_sr()){
                current_node = current_node->right_child;
            } else{
                found_element = true;
                student = current_node->student;
                break;
            }
        }
    }
    void BinarySearchTree::print_pre_order(Node* current_node){

    }
    void BinarySearchTree::print_in_order(Node* current_node){

    }
    void BinarySearchTree::print_pos_order(Node* current_node){

    }