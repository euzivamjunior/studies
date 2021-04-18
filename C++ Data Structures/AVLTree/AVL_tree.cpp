#include <iostream>
#include <cstddef>
#include "AVL_tree.h"

using namespace std;

    // Constructor function
    AVLTree::AVLTree(){
        root = nullptr;
    }
    // Destructor function
    AVLTree::~AVLTree(){
        delete_tree(root);
    }
    /*
        To delete the tree, the tree is traversed in the pos-order
        call function to delete the left node,
        call function to delete the right node,
        delete the current node, and so on, until the current node
        becomes nullptr.
    */
    void AVLTree::delete_tree(Node* current_node){
        if (current_node != nullptr){
            delete_tree(current_node->left_child);
            delete_tree(current_node->right_child);
            delete current_node;
        }
    }
    // get root pointer
    Node* AVLTree::get_root(){
        return root;
    }
    // is empty?
    bool AVLTree::is_empty(){
        return (root == nullptr);
    }
    // the computer memory is full?
    bool AVLTree::is_full(){
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
    void AVLTree::insert(Student student){
        bool grow;
        recursive_insertion(root, student, grow);
    }
    // insertion function by recursive calls
    /*
        Starting in the root node, current node go through the tree until reachs an null
        postion to store this new element.
    */
    void AVLTree::recursive_insertion(Node*& current_node, Student student, bool& grow){
        // Insert the new element when the current node reachs a null position.
        if (current_node == nullptr) {
            current_node = new Node;
            current_node->right_child = nullptr;
            current_node->left_child = nullptr;
            current_node->student = student;
            // the new insert node always is a leaf node, then it's balance_factor is 0.
            current_node->balance_factor = 0;
            // set grow as true to verify if balance factor update is needed
            grow = true;
            return;
        }
        /* 
            Call recursive insertion if the SR element is smaller than current node SR
            with current node as its own left-child.
        */
        if (student.get_sr() < current_node->student.get_sr()){
            recursive_insertion(current_node->left_child, student, grow);
            if (grow){
                current_node->balance_factor -= 1;
            }
        /*
            If the current node is not null, and SR student is not smaller than SR 
            current node, than the SR student is greater (or qual), in this case
            call recursive insertion with current node as its own right-child.
        */
        } else {
            recursive_insertion(current_node->right_child, student, grow);
            if (grow){
                current_node->balance_factor += 1;
            }
        }

        /*
            call make rotation function to verify if the current node is unbalanced 
            (i.e. |balance_factor| > 1) and need a rotation.
        */
        make_rotation(current_node);

        /*
            This statement is to apply the following rule, when a current node
            balance factor becomes 0, then all its upper nodes do not have its
            balance factor changed, i.e. there's no grow, so it's set as false.
        */
        if (grow && current_node->balance_factor == 0){
            grow = false;
        }

    }
    void AVLTree::remove(Student student){
        bool shrink;
        remove_search(student, root, shrink);
    }
    /*
        #######
    */
    void AVLTree::remove_search(Student student, Node*& current_node, bool& shrink){
        if (student.get_sr() < current_node->student.get_sr()){
            remove_search(student, current_node->left_child, shrink);
            if (shrink){
                current_node->balance_factor += 1;
            }
        } else if (student.get_sr() > current_node->student.get_sr()){
            remove_search(student, current_node->right_child, shrink);
            if (shrink){
                current_node->balance_factor -= 1;
            }
        } else{
            delete_node(current_node, shrink);
        }
        // make rotation if the current node is not null.
        if (current_node != nullptr){
            make_rotation(current_node);
            /*
            This statement is to apply the following rule, when a current node
            balance factor becomes 0, then all its upper nodes do not have its
            balance factor changed, i.e. there's no grow, so it's set as false.
            */
            if (shrink && current_node->balance_factor != 0){
                shrink = false;
            }
        }
    }
    void AVLTree::delete_node(Node*& current_node, bool& shrink){
        Node* temp_node = current_node;
        /*
            IF the left child of the current node is null, then the current node pointer
            becomes the right child and the temp node is deleted (searched node to delete).
            this approach will works on the case on the current node has only the right 
            child, when the current_node becomes the pointer to the right child, and
            also works when there's no child on the node, because the right child is
            nullptr, so the current_node becomes the pointer to nullptr.
            finally set shrink as true.

        */
        if (current_node->left_child == nullptr){
            current_node = current_node->right_child;
            shrink = true;
            delete temp_node;
        // similar to the rule above, the same rule is applied by the inverse (right) node.
        } else if (current_node->right_child == nullptr){
            current_node = current_node->left_child;
            shrink = true;
            delete temp_node;
        /*
            In this case the node have both right and left child, then in this case it
            needed to search by a succesor node of the current node that will becomes 
            the current node value. After this, the student_successor (now duclicate as 
            the current node as they have the same value) is deleted by the remove_search() 
            function.
            If shrink was true, then decrease balance factor of the node.
        */
        } else{
            Student student_successor;
            get_successor(student_successor, current_node);
            current_node->student = student_successor;
            remove_search(student_successor, current_node->right_child, shrink);
            if (shrink){
                current_node->balance_factor -= 1;
            }
        }
    }
    /*
        (Student object by reference, to enable changes by the delete_node() function).
        get_successor function runs by the following rule. moves the temp node to the right
        child, then keep moving to the left child until the left_child of the temp node
        becomes nullptr (i.e. there's no left-child), then the student_successor becomes
        the temp_node student object.
    */
    void AVLTree::get_successor(Student& student_successor, Node* temp_node){
        temp_node = temp_node->right_child;
        while (temp_node->left_child != nullptr){
            temp_node = temp_node->left_child;
        }
        student_successor = temp_node->student;
    }
    void AVLTree::search(Student& student, bool& found_element){
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
    /*
        The pre-order print algorythm is given by the following rule:
        Starting with the current node, print this node then calls
        recursively the same function to print(left-child node),
        then calls recursively the same function to
        print(right-child node).
    */
    void AVLTree::print_pre_order(Node* current_node){
        if (current_node != nullptr){
            cout << current_node->student.get_name() << "\t"
                 << current_node->student.get_sr() << endl;
            print_pre_order(current_node->left_child);
            print_pre_order(current_node->right_child);
        }
    }
    void AVLTree::print_in_order(Node* current_node){
        if (current_node != nullptr){
            print_in_order(current_node->left_child);
            cout << current_node->student.get_name() << "\t"
                 << current_node->student.get_sr() << endl;
            print_in_order(current_node->right_child);
        }
    }
    void AVLTree::print_pos_order(Node* current_node){
        if (current_node != nullptr){
            print_pos_order(current_node->left_child);
            print_pos_order(current_node->right_child);
            cout << current_node->student.get_name() << "\t"
                 << current_node->student.get_sr() << endl;
        }
    }
    /*
        RIGHT ROTATION RULE:
        The left_child of the current parent node becomes the new parent node,
        then the right child of the new parent node becomes the left child of
        the previous (old) parent node, and the right child of the new parent 
        node becomes the previous (old) parent child. then the parent node is 
        indeed update as the new parent node. 

    */
    void AVLTree::right_rotation(Node*& parent){
        Node* new_parent = parent->left_child;
        parent->left_child = new_parent->right_child;
        new_parent->right_child = parent;
        parent = new_parent;
    }
    /*
        LEFT ROTATION RULE:
        Similar to the right rotation rule, with inverse rotation.
    */
    void AVLTree::left_rotation(Node*& parent){
        Node* new_parent = parent->right_child;
        parent->right_child = new_parent->left_child;
        new_parent->left_child = parent;
        parent = new_parent;
    }
    /*
        DOUBLE ROTATION - LEFT->RIGHT - RULE:
        First the is made a left rotation in the left child of the parent,
        then the parent left-child becomes the new child (after the left
        rotation the child changes), then is made an right rotation in the
        parente node.
    */
    void AVLTree::left_right_rotation(Node*& parent){
        Node* child = parent->left_child;
        left_rotation(child);
        parent->left_child = child;
        right_rotation(parent);
    }
    /*
        DOUBLE ROTATION - RIGHT->LEFT - RULE:
        Similar to the left_right_rotation, with inverse order.
    */
    
    void AVLTree::right_left_rotation(Node*& parent){
        Node* child = parent->right_child;
        right_rotation(child);
        parent->right_child = child;
        left_rotation(parent);
    }
    // make node rotation
    void AVLTree::make_rotation(Node*& parent){
        Node* child;
        Node* grandchild; // for double rotation

        /*
            The type rotation is made by the parent child balance factor rule.
            ========================================================================
            for PARENT BALANCE FACTOR = -2
            ========================================================================
            || LEFT-CHILD ||    TYPE ROTATION    || new PARENT BF || new CHILD BF ||
            ========================================================================
            ||     -1     ||    right rotation   ||       0       ||       0      ||
            ||      0     ||    right rotation   ||      -1       ||       1      ||
            ||      1     || right-left rotation ||======>GRAND CHILD BF RULE<======
            ========================================================================

            for PARENT BALANCE FACTOR = 2
            ========================================================================
            || LEFT-CHILD ||    TYPE ROTATION    || new PARENT BF || new CHILD BF ||
            ||      1     ||    left rotation    ||       0       ||       0      ||
            ||      0     ||    left rotation    ||       1       ||      -1      ||
            ||     -1     || left-right rotation ||======>GRAND CHILD BF RULE<======
            ========================================================================
        */
        if (parent->balance_factor == -2){
            child = parent->left_child;

            // single right rotation
            if (child->balance_factor == -1){
                parent->balance_factor = 0;
                child->balance_factor = 0;
                right_rotation(parent);
            // single right rotation
            } else if (child->balance_factor == 0){
                parent->balance_factor = -1;
                child->balance_factor = 1;
                right_rotation(parent);
            /*
                First update parent and child balance factor, by the rule,
                followint the current grandchild balance factor, then
                make right-left rotation by parent node.
            */
            } else if (child->balance_factor == 1){
                grandchild = child->right_child;
                if (grandchild->balance_factor == -1){
                    parent->balance_factor = 1;
                    child->balance_factor = 0;
                } else if (grandchild->balance_factor == 0){
                    parent->balance_factor = 0;
                    child->balance_factor = 0;
                } else if (child->balance_factor == 1){
                    parent->balance_factor = 0;
                    child->balance_factor = -1;
                }
                grandchild->balance_factor = 0;
                left_right_rotation(parent);
            }
        } else if(parent->balance_factor == 2){
            child = parent->right_child;

            // single left rotation
            if (child->balance_factor == 1){
                parent->balance_factor = 0;
                child->balance_factor = 0;
                left_rotation(parent);
            // single left rotation
            } else if (child->balance_factor == 0){
                parent->balance_factor = 1;
                child->balance_factor = -1;
                left_rotation(parent);
            /*
                First update parent and child balance factor, by the rule,
                followint the current grandchild balance factor, then
                make left-child rotation by parent node.
            */
            } else if (child->balance_factor == -1){
                grandchild = child->left_child;
                if (grandchild->balance_factor == -1){
                    parent->balance_factor = 0;
                    child->balance_factor = 1;
                } else if (grandchild->balance_factor == 0){
                    parent->balance_factor = 0;
                    child->balance_factor = 0;
                } else if (child->balance_factor == 1){
                    parent->balance_factor = -1;
                    child->balance_factor = 0;
                }
                grandchild->balance_factor = 0;
                right_left_rotation(parent);
            }
        }
    }
