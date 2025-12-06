#include <iostream>
#include "headers/Dijkstra.hpp"

using namespace std;

int main() {
    // Create a graph with 5 nodes (0 to 4)
    Dijkstra g(5);

    // Add edges: g.addEdge(src, to, weight)
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 4, 1);

    int source = 0;
    vector<int> distances = g.shortestPath(source);

    cout << "Shortest distances from node " << source << ":\n";
    for(int i = 0; i < distances.size(); i++) {
        cout << "Node " << i << ": ";
        if(distances[i] == 999) cout << "INF";
        else cout << distances[i];
        cout << endl;
    }

    return 0;
}

// output
// Shortest distances from node 0:
// Node 0: 0
// Node 1: 2
// Node 2: 3
// Node 3: 4
// Node 4: 5
