// simple graph, undirected , weighted.
// pt-BR grafo simples, n�o-direcionado, ponderado (aresta possui peso).
#include <iostream>

using namespace std;

typedef string ItemType;

class Graph{
    private:
    int null_edge; // pt-BR aresta nula.
    int max_vertices;
    int num_vertices;
    ItemType* vertices; // (n�).
    /*
        '**': pointer to a pointer,
        in this case to indicate an array of arrays,
        (vector of vectors = matrix).
    */
    int** adjacency_matrix; //**: vector of vectors

    public:
    Graph(int m_edge, int n_edge);
    ~Graph();
    int get_index(ItemType item);
    bool is_full();
    void insert_vertex(ItemType item); // pt-BR vertex = v�rtice
    void insert_edge(ItemType output_node, ItemType input_node, int weight); // node = vertex
    int get_weight(ItemType output_node, ItemType input_node);
    int get_degree(ItemType item);
    void print_matrix();
    void print_vertices();
};