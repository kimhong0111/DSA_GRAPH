#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <queue>
#include <limits>

struct Edge {
    int to;
    int weight;
};

struct DijkstraResult {
    std::vector<int> dist;
    std::vector<int> parent;
};

class Dijkstra {
private:
    int n;
    std::vector<std::vector<Edge>> graph;

public:
    Dijkstra(int n);
    void addEdge(int src, int to, int weight);
    DijkstraResult run(int src);
};

#endif
