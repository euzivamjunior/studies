#include "student.h"

class Hash{
    private:
    int hash_function(Student student);
    int max_items;
    int max_positions;
    int number_items;
    Student* structure;

    public:
    Hash(int vector_size, int max);
    ~Hash();
    bool is_full();
    int get_length();
    void push(Student student);
    void to_delete(Student student);
    void search(Student& student, bool& search_result);
    void print();
};