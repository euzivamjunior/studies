// simple graph, directed , weighted.
// pt-BR grafo simples, direcionado, ponderado (aresta possui peso).
#include <iostream>
#include "dynamic_queue.h"
#include "dynamic_stack.h"

using namespace std;

typedef string ItemType;

class Graph{
    private:
    int null_edge; // pt-BR aresta nula.
    int max_vertices;
    int num_vertices;
    ItemType* vertices; // (nó).
    /*
        '**': pointer to a pointer,
        in this case to indicate an array of arrays,
        (vector of vectors = matrix).

        **: vector of vectors
    */
    int** adjacency_matrix;
    // highlight all nodes already visited by the search algorithm
    bool* highlighter; //pt-BR marcador

    public:
    Graph(int m_edge, int n_edge);
    ~Graph();
    int get_index(ItemType item);
    bool is_full();
    void insert_vertex(ItemType item); // pt-BR vertex = vértice
    void insert_edge(ItemType output_node, ItemType input_node, int weight); // node = vertex
    int get_weight(ItemType output_node, ItemType input_node);
    int get_degree(ItemType item);
    void print_matrix();
    void print_vertices();

    // set false (unvisited vertex) to all nodes before runs the search.
    void clear_highlighter();
    // breadth_first_search algorithm
    void breadth_first_search(ItemType origin, ItemType destination); // pt-BR busca em largura
    // depth first search (BFS) algorithm
    void depth_first_search(ItemType origin, ItemType destination); // pt-BR busca em profundidade
};