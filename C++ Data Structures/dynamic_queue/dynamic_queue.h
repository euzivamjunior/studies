// define default type for stack object
typedef int ItemType;

struct Node
{
    // value of node
    ItemType value;
    // pointer to the next node
    Node* next;
};

class DynamicQueue{
    private:
    // pointer to front/first node
    Node* front;
    // pointer to rear/last node
    Node* rear;

    public:
    // constructor
    DynamicQueue();
    // destructor
    ~DynamicQueue();

    // check if queue is empty
    bool is_empty();
    // check if queue is full
    bool is_full();
    // insert an element in the queue
    void enqueue(ItemType item);
    // remove an element from the queue
    ItemType dequeue();
    // print all elements in the queue
    void print();
};
