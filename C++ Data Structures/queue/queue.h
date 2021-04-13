// define default type for stack object
typedef int ItemType;
// max number of itens on the queue
const int max_itens = 100;

class Queue{
    private:
    // first, last element
    int first, last;
    // structure pointer
    ItemType* structure;

    public:
    // constructor
    Queue();
    // destructor
    ~Queue();

    // check if queue is full
    bool is_full();
    // check if queue is empty
    bool is_empty();
    // insert an element in the queue
    void enqueue(ItemType item);
    // remove an element from the queue
    ItemType dequeue();
    // print all elements in the queue
    void print();
    // return lenght (number) of elements on the stack
    int lenght();
};