#include <iostream>
#include <vector>

using namespace std;

int counter = 1;

void addEdge(vector<vector<int>>& v, int x, int y) {
    v[x].push_back(y);
    v[y].push_back(x);
}

void dfs(vector<vector<int>>& v, vector<bool>& visited, int startNode, vector<int>& pre, vector<int>& post) {
    pre[startNode] = counter;
    counter++;
    visited[startNode] = true;

    for (int neighbour : v[startNode]) {
        if (!visited[neighbour])
            dfs(v, visited, neighbour, pre, post);
    }

    post[startNode] = counter;
    counter++;
}



int main() {
    int vertices = 7;
    vector<vector<int>> v(vertices);
    vector<bool> visited(vertices, false);
    vector<int> pre(vertices);
    vector<int> post(vertices);
    addEdge(v, 1, 2);
    addEdge(v, 1, 3);
    addEdge(v, 2, 4);
    addEdge(v, 4, 3);
    addEdge(v, 3, 5);
    addEdge(v, 5, 6);

    dfs(v, visited, 1, pre, post);

    for(int i = 1; i < vertices; i++)
    cout << "Node " << i << " Pre number "
            << pre[i] << " Post number "
            << post[i] << endl;

    return 0;
}