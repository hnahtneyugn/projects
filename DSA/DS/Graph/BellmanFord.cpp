#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<pair<int, int>>>& edgeList, int u, int v, int w) {
    edgeList[u].push_back({v, w});
}

bool BellmanFord(vector<vector<pair<int, int>>>& edgeList, vector<int>& distance, int vertices) {

    // it has been proven that to find the shortest path, it can only be optimised 
    // for the maximum time of v-1 times, with v = vertices
    for (int i = 0; i < vertices - 1; ++i) {
        for (int u = 0; u < vertices; ++u) {
            for (const auto& edge : edgeList[u]) {
                int v = edge.first;
                int w = edge.second;
                if(distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // finally, optimise for the vertices-nth time
    // if found any changes in the distances, it means there is a negative cycle
    for (int u = 0; u < vertices; ++u) {
        for (const auto& edge : edgeList[u]) {
            int v = edge.first;
            int w = edge.second;
            if(distance[u] != INT_MAX && distance[v] > distance[u] + w) {
                return true;
            }
        }
    }

    // if not contain negative cycle, return false
    return false;
}

int main() {
    int vertices = 6; 
    vector<vector<pair<int, int>>> edgeList(vertices);
    addEdge(edgeList, 0, 1, 5);
    addEdge(edgeList, 1, 2, 1);
    addEdge(edgeList, 1, 3, 2);
    addEdge(edgeList, 2, 4, 1);
    addEdge(edgeList, 3, 5, 2);
    addEdge(edgeList, 4, 3, -1);    
    addEdge(edgeList, 5, 4, -3);

    int source = 0;
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    if (BellmanFord(edgeList, distance, vertices)) 
        cout << "Graph contains a negative cycle!\n";
    else 
        cout << "Graph doesn't contain a negative cycle!\n";

    cout << "Distance from source vertex " << source << ":" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << " -> " << distance[i] << endl;
    }

    return 0; 
}