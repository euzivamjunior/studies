// simple graph, undirected , weighted.
// pt-BR grafo simples, não-direcionado, ponderado (aresta possui peso).
#include <iostream>

using namespace std;

typedef string ItemType;

class Graph{
    private:
    int null_edge; // pt-BR aresta nula.
    int max_edges;
    int num_edges;
    ItemType* vertex; // pt-BR vértice (nó).
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
    void insert_vertex(ItemType item);
    void insert_edge(ItemType output_node, ItemType input_node, int weight); // node = vertex
    int get_height(ItemType output_node, ItemType input_node);
    int get_degree(ItemType item);
    void print_matrix();
    void print_vertices();
};