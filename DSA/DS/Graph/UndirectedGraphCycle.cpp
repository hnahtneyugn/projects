#include <iostream>
#include <vector>

using namespace std;

bool cycle = false;

void addEdge(vector<vector<int>>& v, int x, int y) {
    v[x].push_back(y);
    v[y].push_back(x);
}

void dfs(vector<vector<int>>& v, vector<bool>& visited, int children, int parent) {
    visited[children] = true;
    
    for (int neighbour : v[children]) {
        if (!visited[neighbour]) {
            dfs(v, visited, neighbour, children);
        } 
        else
            if (neighbour != parent)
                cycle = true; 
    }
}

void dfsCall(vector<vector<int>>& v, vector<bool>& visited, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i])
            dfs(v, visited, i, -1);
    }
}

int main() {
    int vertices = 5;
    vector<vector<int>> v(vertices);
    vector<bool> visited(vertices, false);
    addEdge(v, 1, 0);
    addEdge(v, 0, 2);
    addEdge(v, 2, 1);
    addEdge(v, 0, 3);
    addEdge(v, 3, 4);
    dfsCall(v, visited, vertices);

    if (cycle)
        cout << "Graph contains cycle!";
    else    
        cout << "Graph doesn't contain cycle!";

    return 0;
}