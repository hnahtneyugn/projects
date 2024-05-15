#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// function to add an edge
void addEdge(vector<vector<int>>& v, int x, int y) {
    v[x].push_back(y);
}

// bfs traversing through every node
void bfs(vector<vector<int>>& v, vector<bool>& visited, int startNode) {
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // if the neighbour nodes are not visited yet, then push them into the queue
        for (int neighbour : v[currentNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

void bfsCall(vector<vector<int>>& v, vector<bool>& visited, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            bfs(v, visited, i);
        }
    }
}

int main() {
    int vertices = 5;
    vector<vector<int>> v(vertices);
    vector<bool> visited(vertices, false);
    addEdge(v, 0, 4);
    addEdge(v, 1, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 4);
    addEdge(v, 2, 3);
    addEdge(v, 3, 4);

    cout << "BFS Traversal:\n";
    bfsCall(v, visited, vertices);

    return 0;
}
