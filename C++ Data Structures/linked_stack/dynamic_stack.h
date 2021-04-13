// define default type for dynamic stack object
typedef int ItemType;

/*
    STRUCT
    ---------------------------------------------------------------------------------------
    structure in this case is similar to an class.
    To know more about the differences between struct and class, access the link below
    https://pt.stackoverflow.com/questions/16181/qual-a-diferen%C3%A7a-entre-struct-e-class

    STRUCT NODE 
    ---------------------------------------------------------------------------------------
    is used to generate an object with 2 atributes:
        value, that is used to store an value of 'ItemType' type
        next, is a pointer to save the next node in the dynamic stack.
*/
struct Node{
    // value of node
    ItemType value;
    // pointer to the next node
    Node* next;
};

class DynamicStack{
    private:
    // pointer to top node
    Node* TopNode;

    public:
    // constructor
    DynamicStack();
    // destructor
    ~DynamicStack();
    // check if dynamic stack is empty
    bool is_empty();
    // check if there are memory available to a new node
    bool is_full();
    // insert an element in the dynamic stack
    void push(ItemType item);
    // remove an element from the dynamic stack
    ItemType pull();
    // print all elements in the dynamic stack
    void print();
};