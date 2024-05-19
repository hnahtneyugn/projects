#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& v, int x, int y) {
    v[x].push_back(y);
}

bool dfs(vector<vector<int>>& v, vector<bool>& visited, vector<bool>& recStack, int currentNode) {
    if (!visited[currentNode]) {
        // Mark the current node as visited and part of recursion stack
        visited[currentNode] = true;
        recStack[currentNode] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int neighbour : v[currentNode]) {
            if (!visited[neighbour] && dfs(v, visited, recStack, neighbour))
                return true;
            else if (recStack[neighbour])
                return true;
        }
    }
    // Remove the vertex from recursion stack
    recStack[currentNode] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& v, int vertices) {
    vector<bool> visited(vertices, false);
    vector<bool> recStack(vertices, false);

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int i = 0; i < vertices; i++)
        if (!visited[i] && dfs(v, visited, recStack, i))
            return true;

    return false;
}

int main() {
    int vertices = 6;
    vector<vector<int>> v(vertices);
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 2, 3);
    addEdge(v, 3, 4);
    addEdge(v, 3, 0);
    addEdge(v, 5, 3);

    if (isCyclic(v, vertices))
        cout << "Graph contains cycle!";
    else    
        cout << "Graph doesn't contain cycle!";

    return 0;
}
