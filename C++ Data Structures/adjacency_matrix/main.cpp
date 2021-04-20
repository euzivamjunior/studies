#include <iostream>
#include "graph.h"

using namespace std;

int main(){
    int max, null_edge_value;
    cout << "Enter the maximum vertices number: ";
    cin >> max;

    cout << "Enter the value representation for null edge:  ";
    cin >> null_edge_value;

    Graph graph1(max, null_edge_value);
    ItemType item1, item2;

    int control, value, weight;

    do{
        cout << endl;
        cout << "Enter 0 to stop the exit the script!" << endl;
        cout << "Enter 1 to insert a vertex!" << endl;
        cout << "Enter 2 to remove a vertex!" << endl;
        cout << "Enter 3 to print the degree of an vertex!" << endl;
        cout << "Enter 4 to print the weight of an edge" << endl;
        cout << "Enter 4 to print the adjacency matrix" << endl;
        cout << "Enter 4 to print all the vertices" << endl;
        cout << "Your choice: ";
        cin >> control;

        if (control == 1){
            cout << "Enter the vertex element to be inserted: ";
            cin >> item1;
            graph1.insert_vertex(item1);
        } else if (control == 2){
            cout << "Enter the output vertex: ";
            cin >> item1;

            cout << "Enter the input vertex: ";
            cin >> item2;

            cout << "Enter the edge weight: ";
            cin >> weight;

            graph1.insert_edge(item1, item2, weight);
        } else if (control == 3){
            cout << "Enter the desired vertex: ";
            cin >> item1;

            value = graph1.get_degree(item1);
            cout << "The " << item1 << " vertex degree is: " << value << endl;
        } else if (control == 4){

        } else if (control == 5){
            graph1.print_matrix();
        } else if (control == 6){
            graph1.print_vertices();
        }

    } while (control != 0);

    return 0;
}