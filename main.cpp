#include <iostream>
#include "./Graph/dijkstra.cpp"
#include "./Graph/graph.cpp"



int main(){
    GraphRoute g; 

    g.addLocation("A", "Alpha", 0, 0, 'C');
    g.addLocation("B", "Beta", 3, 4, 'C');
    g.addLocation("C", "Gamma", 6, 8, 'C');

    g.addRoute("A", "B");
    g.addRoute("B", "C");
    g.addRoute("A", "C");
    g.addRoute("C", "A");

    auto path = g.getShortestPath("B", "A");

    std::cout << "Shortest Path B → A:\n";
    for (auto &s : path) {
        std::cout << s << " ";
    }

   return 0;
    
}
