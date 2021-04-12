
// define default type for stack object
typedef int ItemType;
// max number of itens on the stack
const int max_itens = 100;


class Stack{
    private:
    // stack size
    int size;
    // structure pointer
    ItemType* structure;

    public:
    // constructor
    Stack();
    // destructor
    ~Stack();

    // check if stack is full (on max item number)
    bool is_full();
    // check if stack is empty
    bool is_empty();
    // add an element to the stack
    void push(ItemType item);
    // remove an element from stack
    ItemType pop();
    // print all elements on the stack
    void print();
    // return lenght (number) of elements on the stack
    int lenght();

};