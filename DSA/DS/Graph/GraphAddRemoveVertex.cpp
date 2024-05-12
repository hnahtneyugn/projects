#include <iostream>
#include <vector>

using namespace std;

int n = 6;
vector<vector<int>> v(n);

// utility function to print a graph
void printGraph(vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << i << " -> ";
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

// add a new edge between vertices x and y
void addEdge(int x, int y) {
    v[x].push_back(y);
    v[y].push_back(x);
}

// add a new vertex 
void addVertex(int vertex, int x, int y) {
    addEdge(vertex, x);
    addEdge(vertex, y);
}

int main() {
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(3, 2);
    addEdge(4, 3);

    cout << "Original Graph:\n";
    printGraph(v);

    addEdge(1, 4);
    addEdge(0, 2);
    cout << "Graph after adding edges:\n";
    printGraph(v);

    addVertex(5, 3, 2);
    addVertex(5, 1, 0);
    cout << "Graph after adding vertex 5:\n";
    printGraph(v);

    return 0;
}