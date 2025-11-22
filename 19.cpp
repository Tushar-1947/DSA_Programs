#include <iostream>
using namespace std;

int main() {
    int nodes, edges;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Create adjacency matrix initialized with 0
    int adj[100][100] = {0};

    cout << "Is the graph directed? (1=yes, 0=no): ";
    int directed;
    cin >> directed;

    cout << "\nEnter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;

        if (!directed)        // If undirected graph
            adj[v][u] = 1;
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
