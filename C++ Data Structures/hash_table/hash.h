#include "student.h"

class Hash{
    private:
    int hash_function(Student student);
    int max_itens;
    int max_positions;
    int number_itens;
    Student* structure;

    public:
    Hash();
    ~Hash();
    bool is_full();
    int get_lenght();
    void push(Student student);
    void to_delete(Student student);
    void search(Student& student, bool& search);
    void print();
};