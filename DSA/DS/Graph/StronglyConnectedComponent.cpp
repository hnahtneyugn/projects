// The hardest algorithm that I could comprehend fully (now - 20th May 2024)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int order = 1;

void addEdge(vector<vector<int>>& edgeList, int u, int v) {
    edgeList[v].push_back(u);
}

// main function
void SCC(vector<vector<int>>& edgeList ,vector<int>& num, vector<int>& lowest, vector<bool>& processing, stack<int>& s, int u) {
    // first, initialize lowest of a vertex equal to its order
    num[u] = lowest[u] = order++;
    s.push(u);
    processing[u] = true;

    // traverse all the neighbour v of the current vertex u
    for (const auto& v : edgeList[u]) {
        // if v is not visited yet, visit it
        // this is the case of normal forward tree edge
        if (num[v] == -1) {
            SCC(edgeList, num, lowest, processing, s, v);   
            
            // after visiting v, set the lowest of vertex u to the min of lowest[u] and lowest[v]
            // because both u and its child v are pointing to their same furthest ancestor
            lowest[u] = min(lowest[u], lowest[v]);
        }
        // else, if v is already being processed
        // then it is a back edge from u to v
        // then update lowest of u to min of lowest[u] and num[v]
        else if (processing[v] == true) {
            lowest[u] = min(lowest[u], num[v]);
        }
    }

    // either the SCC has only one vertex,
    // or the SCC has many vertices, and u is the head of it
    // in the second case, u is an articulation point
    // removing u will result in an increase in components
    int w;
    if (lowest[u] == num[u]) {
        while (s.top() != u) {
            w = s.top();
            cout << w << " ";
            processing[w] = false;
            s.pop();
        }

        w = s.top();
        cout << w << "\n";
        processing[w] = false;
        s.pop();
    }
}

// call the function on vertices which haven't been visited yet
void SCCcall(vector<vector<int>>& edgeList, vector<int>& num, vector<int>& lowest, vector<bool>& processing, int vertices, stack<int>& s) {
    for (int i = 0; i < vertices; ++i)
        if (num[i] == -1)
            SCC(edgeList, num, lowest, processing, s, i);
}

int main() {
    int vertices = 10;

    // adjacency list
    vector<vector<int>> edgeList(vertices);

    // the order which DFS travel through the vertices
    vector<int> num(vertices, -1);

    // lowest[i] shows the topmost reachable ancestor of i
    vector<int> lowest(vertices, -1);

    // true when a vertex is being processed
    vector<bool> processing(vertices, false);

    // create stack for DFS
    stack<int> s;

    addEdge(edgeList, 0, 1);
    addEdge(edgeList, 0, 3);
    addEdge(edgeList, 1, 2);
    addEdge(edgeList, 1, 4);
    addEdge(edgeList, 2, 0);
    addEdge(edgeList, 2, 6);
    addEdge(edgeList, 3, 2);
    addEdge(edgeList, 4, 5);
    addEdge(edgeList, 4, 6);
    addEdge(edgeList, 5, 6);
    addEdge(edgeList, 5, 7);
    addEdge(edgeList, 5, 8);
    addEdge(edgeList, 5, 9);
    addEdge(edgeList, 6, 4);
    addEdge(edgeList, 7, 9);
    addEdge(edgeList, 8, 9);
    addEdge(edgeList, 9, 8);

    SCCcall(edgeList, num, lowest, processing, vertices, s);

    return 0;
}