#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<pair<int, int>>>& edgeList, int u, int v, int w) {
    edgeList[u].push_back({v, w});
    edgeList[v].push_back({u, w});
}

void Dijkstra(vector<vector<pair<int, int>>>& edgeList, vector<int>& distance) {
    // using a min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});        // starts with vertex 0

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        // calculate each path and choose the minimum value vertex only
        // edge.first: distance at that vertex
        // edge.second: the vertex

        for (const auto& edge : edgeList[u]) {
            int v = edge.first;
            int w = edge.second;

            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }
}

void printGraph(int vertices, vector<int>& distance) {
    cout << "Vertex distance from source:\n";
    for (int i = 0; i < vertices; ++i)
        cout << "Distance from 0 to " << i << ": " << distance[i] << "\n";
}


int main() {
    int vertices = 9;
    vector<int> distance(vertices, INT_MAX);
    vector<vector<pair<int, int>>> edgeList(vertices);
    distance[0] = 0;

    addEdge(edgeList, 0, 1, 4);
    addEdge(edgeList, 0, 7, 8);
    addEdge(edgeList, 1, 2, 8);
    addEdge(edgeList, 1, 7, 11);
    addEdge(edgeList, 2, 3, 7);
    addEdge(edgeList, 2, 8, 2);
    addEdge(edgeList, 2, 5, 4);
    addEdge(edgeList, 3, 4, 9);
    addEdge(edgeList, 3, 5, 14);
    addEdge(edgeList, 4, 5, 10);
    addEdge(edgeList, 5, 6, 2);
    addEdge(edgeList, 6, 7, 1);
    addEdge(edgeList, 6, 8, 6);
    addEdge(edgeList, 7, 8, 7);

    Dijkstra(edgeList, distance);
    printGraph(vertices, distance);

    return 0;
}