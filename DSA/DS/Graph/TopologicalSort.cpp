#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& v, int x, int y) {
    v[x].push_back(y);
}

// simply using DFS and print the stack
// however, since we need the stack to print, we will push it after DFS recursion

void TopoSort(vector<vector<int>>& v, vector<bool>& visited, stack<int>& s, int startNode) {
    visited[startNode] = true;
    for (int neighbour : v[startNode]) {
        if (!visited[neighbour])
            TopoSort(v, visited, s, neighbour);
    }

    s.push(startNode);
}

void TopoSortCall(vector<vector<int>>& v, vector<bool>& visited, stack<int>& s, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i])
            TopoSort(v, visited, s, i);
    }
}

void printStack(stack<int>& s) {
    cout << "The topological order is: \n";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int vertices = 4;
    vector<vector<int>> edgeList(vertices);
    vector<bool> visited(vertices, false);
    stack<int> s;
    addEdge(edgeList, 0, 1);
    addEdge(edgeList, 1, 2);
    addEdge(edgeList, 3, 1);
    addEdge(edgeList, 3, 2);

    TopoSortCall(edgeList, visited, s, vertices);
    printStack(s);

    return 0;
}