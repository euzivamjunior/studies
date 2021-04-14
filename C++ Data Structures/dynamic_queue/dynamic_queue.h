
typedef int ItemType;

struct Node
{
    ItemType value;
    Node* next;
};

class DynamicQueue{
    private:
    Node* front;
    Node* rear;

    public:
    DynamicQueue();
    ~DynamicQueue();

    bool is_empty();
    bool is_full();
    void enqueue(ItemType item);
    ItemType dequeue();
    void print();
};
