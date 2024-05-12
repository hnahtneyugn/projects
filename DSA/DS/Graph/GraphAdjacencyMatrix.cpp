#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createAdjacencyMatrix(vector<vector<int>>& graph, int numVertices) {
    // Initialize the adjacency matrix with zeros
    vector<vector<int> > adjMatrix(numVertices, vector<int>(numVertices, 0));

    // Fill the adjacency matrix based on the edges in the graph
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (graph[i][j] == 1) {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i]= 1; // For undirected graph, set symmetric entries
            }
        }
    }

    return adjMatrix;
}

int main() {
    // The indices represent the vertices, and the values are lists of neighboring vertices
    vector<vector<int>> graph = { { 0, 1, 0, 0 },
                                   { 1, 0, 1, 0 },
                                   { 0, 1, 0, 1 },
                                   { 0, 0, 1, 0 } };

    int numVertices = graph.size();

    // Create the adjacency matrix
    vector<vector<int> > adjMatrix
        = createAdjacencyMatrix(graph, numVertices);

    // Print the adjacency matrix
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}