// simple graph, directed , weighted.
// pt-BR grafo simples, direcionado, ponderado (aresta possui peso).
#include <iostream>
#include "graph.h"
#include "dynamic_queue.h"
#include "dynamic_stack.h"

using namespace std;

Graph::Graph(int m_edge, int n_edge){ // Constructor
    num_vertices = 0;
    max_vertices = m_edge;
    null_edge = n_edge;

    // declare bool vector with n (max_vertices) vertices
    highlighter = new bool[max_vertices];

    // declare ItemType vector with n (max_vertices) vertices
    vertices = new ItemType[max_vertices];

    // declare vector of int vectors // rows
    adjacency_matrix = new int*[max_vertices];
    // for each vector, declares an int vector. // columns
    for (int i = 0; i < max_vertices; i++){
        adjacency_matrix[i] = new int[max_vertices];
    }

    // complete all the adjacency matrix with null_edge values
    for (int row = 0; row < max_vertices; row++){
        for (int column = 0; column < max_vertices; column++){
            adjacency_matrix[row][column] = null_edge;
        }
    }
}
Graph::~Graph(){
    // delete vertices
    delete[] vertices;
    // delete all row vectors inside adjacency vector
    for (int row = 0; row < max_vertices; row++){
        for (int column = 0; column < max_vertices; column++){
            delete[] adjacency_matrix[row];
        }
    }
    // delete adjacency vector;
    delete adjacency_matrix;
}
// go through the adjacency matrix, when find the item, return it's index
int Graph::get_index(ItemType item){
    int index = 0;
    while (item != vertices[index])
    {
        index++;
    }
    return index;
}
bool Graph::is_full(){
    return (num_vertices == max_vertices);
}
void Graph::insert_vertex(ItemType item){
    if (is_full()){
        cout << "The max number of vertices has been reached" << endl;
        cout << "The new vertex could not be inserted" << endl;
    }
    else{
        vertices[num_vertices] = item;
        num_vertices++;
    }
}
void Graph::insert_edge(ItemType output_node, ItemType input_node, int weight){ // node = vertex
    int row = get_index(output_node);
    int column = get_index(input_node);

    /*
        As this graph is undirected, then the weight is inserted in two diagonal mirror positions.
    */
    adjacency_matrix[row][column] = weight;
    // adjacency_matrix[column][row] = weight; // removed as the graph was changed to directed type.
}
int Graph::get_weight(ItemType output_node, ItemType input_node){
    int row = get_index(output_node);
    int column = get_index(input_node);
    return (adjacency_matrix[row][column]);
}
// go through the row index sum all the elements != null_edge.
int Graph::get_degree(ItemType item){
    int row = get_index(item);
    int degree = 0;
    for (int element=0; element<max_vertices; element++){
        if (adjacency_matrix[row][element] != null_edge){
            degree++;
        }
    }
    return degree;
}
void Graph::print_matrix(){
    cout << "ADJACENCY MATRIX:" << endl;
    for (int row = 0; row < max_vertices; row++){
        for (int column = 0; column < max_vertices; column++){
            cout << adjacency_matrix[row][column] << " ";
        }
        cout << endl;
    }
}
void Graph::print_vertices(){
    cout << "VERTICES LIST:" << endl;
    for (int index=0; index<num_vertices; index++){
        cout << index << ":\t" << vertices[index] << endl;
    }
}
// set false (unvisited vertex) to all nodes before runs the search.
void Graph::clear_highlighter(){
    for (int index = 0; index < max_vertices; index++){
        highlighter[index] = false;
    }
}

// breadth_first_search (BFS) algorithm | pt-BR busca em largura
void Graph::breadth_first_search(ItemType origin, ItemType destination){
    DynamicQueue queue_vertices;
    bool found = false;
    // uncheck all the vertices
    clear_highlighter();
    // start search vertex
    queue_vertices.enqueue(origin);

    do{
        ItemType current_vertex = queue_vertices.dequeue();
        // If found
        if (current_vertex == destination){
            cout << "Exploring: " << current_vertex << endl;
            cout << "Path found!" << endl;
            found = true;
        } else{
            int index = get_index(current_vertex);
            cout << "Exploring: " << current_vertex << endl;
            // explore all edges (adjacents vertex) from the current vertex, if not highlighted.
            for (int postition=0; postition<max_vertices; postition++){
                if (adjacency_matrix[index][postition] != null_edge){
                    if (!highlighter[postition]){
                        // "Enqueue explored (visited) node (vertex)"
                        cout << "Enqueue: " << vertices[postition] << endl;
                        queue_vertices.enqueue(vertices[postition]);
                        highlighter[postition] = true;
                    }
                }
            }
        }
    } while (!queue_vertices.is_empty() && !found);
    
    if (!found){
        cout << "Path not found :(" << endl;
    }
}
// depth first search (DFS) algorithm | pt-BR busca em profundidade
void Graph::depth_first_search(ItemType origin, ItemType destination){
    DynamicStack stack_vertices;
    bool found = false;
    // uncheck all the vertices
    clear_highlighter();
    // start search vertex
    stack_vertices.push(origin);
    do{
        ItemType current_vertex = stack_vertices.pull();
        // If found
        if (current_vertex == destination){
            cout << "Exploring: " << current_vertex << endl;
            cout << "Path found!" << endl;
            found = true;
        } else{
            int index = get_index(current_vertex);
            cout << "Exploring: " << current_vertex << endl;
            // explore all edges (adjacents vertex) from the current vertex, if not highlighted.
            for (int postition=0; postition<max_vertices; postition++){
                if (adjacency_matrix[index][postition] != null_edge){
                    if (!highlighter[postition]){
                        // "Stacking explored (visited) node (vertex)"
                        cout << "Stacking up: " << vertices[postition] << endl;
                        stack_vertices.push(vertices[postition]);
                        highlighter[postition] = true;
                    }
                }
            }
        }
    } while (!stack_vertices.is_empty() && !found);

    if (!found){
        cout << "Path not found :(" << endl;
    }
}
