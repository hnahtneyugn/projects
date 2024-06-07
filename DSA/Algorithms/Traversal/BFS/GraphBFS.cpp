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
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

int main() {
    int vertices = 5;
    vector<vector<int>> v(vertices);
    vector<bool> visited(vertices, false);
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 4);
    addEdge(v, 2, 4);

    cout << "BFS Traversal:\n";
    bfs(v, visited, 0);

    return 0;
}
