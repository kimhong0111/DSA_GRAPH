#include "../headers/Dijkstra.hpp"

Dijkstra::Dijkstra(int n){
    this->n = n;
    this->graph.resize(n);
}

void Dijkstra::addEdge(int src, int to, int weight) {
    graph[src].push_back({to, weight});
}

DijkstraResult Dijkstra::run(int src) {
    std::vector<int> dist(n, 9999);
    std::vector<int> parent(n, -1);

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

    dist[src] = 0;  
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto &edge : graph[node]) {
            int v = edge.to;
            int w = edge.weight;
            
            if (dist[node] + w < dist[v]) {
                dist[v] = dist[node] + w;
                parent[v] = node;
                pq.push({dist[v], v});
            }
        }
    }

    return { dist, parent };
}
