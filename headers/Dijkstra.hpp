#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Edge {
    int to;
    int weight;
};

class Dijkstra{
private:
    int n; //number of nodes
    vector<vector<Edge>> graph; // this is the method to store the node in the graph abd each node have a vector of edges. ex graph[i] = vector<Edge> (neightbor of graph[i])
public:
    Dijkstra(int n) {
        graph.resize(n);
        this->n = n;
    }

    void addEdge(int src, int to, int weight) {
        graph[src].push_back({to, weight}); // direct graph
    }

    vector<int> shortestPath(int src) {
        //below, we create a vector of dist n size with each one have the value of 999
        vector<int> dist(n, 999); // store the distance from src to differnt node
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // use pq to find the shortest route from src to one node and store the shortest route in dist above

        dist[src] = 0; // the weight from src to itself is 0
        pq.push({0, src}); // weight, node push to pq

        while(!pq.empty()) { // lop to find the shortest route for the node[i] in pq
            pair<int,int> shortestDist = pq.top();
            int weight = shortestDist.first;
            int neighbor = shortestDist.second;
            pq.pop();

            if(weight > dist[neighbor]) continue;
            
            for(Edge &edge : graph[neighbor]) {
                int toNode = edge.to;
                int edgeWeight = edge.weight;

                if(dist[neighbor] + edgeWeight < dist[toNode]) {
                    dist[toNode] = dist[neighbor] + edgeWeight;
                    pq.push({dist[toNode], toNode});
                }
            }
        }

        return dist;
    }    

};