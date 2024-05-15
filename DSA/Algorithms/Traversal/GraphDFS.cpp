#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& v, int x, int y) {
    v[x].push_back(y);
}

void dfs(vector<vector<int>>& v, vector<bool>& visited, int startNode) {
    stack<int> s;

    s.push(startNode);
    visited[startNode] = true;

    while (!s.empty()) {
        int currentNode = s.top();
        s.pop();
        cout << currentNode << " ";

        for (int neighbour : v[currentNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                s.push(neighbour);
            }
        }
    } 
}

int main() {
    int vertices = 4;
    vector<vector<int>> v(vertices);
    vector<bool> visited(vertices, false);
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 2);
    addEdge(v, 2, 0);
    addEdge(v, 2, 3);
    addEdge(v, 3, 3);

    cout << "DFS Traversal:\n";
    dfs(v, visited, 2);

    return 0;
}