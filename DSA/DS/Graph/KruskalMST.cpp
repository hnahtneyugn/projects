#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
    int* parent;
    int* rank;

public:

// construct parent and rank array
// all parent should starts with -1 because we haven't found parent yet
// all rank should starts with 1

DisjointSet(int n) {
    parent = new int [n];
    rank = new int [n];

    for (int i = 0; i < n; ++i) {
        parent[i] = -1;
        rank[i] = 1;
    }
}

~DisjointSet() {
    delete[] parent;
    delete[] rank;
}

// find the root of a vertex
// while finding, if it is a root itself, returns itself
// otherwise, use path compression to cut the graph in half

int findParent(int i) {
    if (parent[i] == -1) 
        return i; 

    parent[i] = findParent(parent[i]); 
    return parent[i];
}

// only unite if x and y are not connected yet
void unite(int x, int y) {
    // find root of x and y
    int p = findParent(x);
    int q = findParent(y);

    if (p != q) {
        if (rank[p] < rank[q])
            parent[p] = q;
        else if (rank[p] > rank[q])
            parent[q] = p;
        else {
            parent[q] = p;
            rank[p]++;
        }
    }
}
};

class Graph{
private:
    vector<pair<int, pair<int, int>>> edgeList;
    int vertices;
    
public:
    Graph(int vertices) {
        this->vertices = vertices;
    }

    void addEdge(int w, int x, int y) {
        // weight - edge
        edgeList.push_back({w, {x, y}});
    }

    void kruskalMST() {
        // sort all the weights (pair.first)
        sort(edgeList.begin(), edgeList.end());
        DisjointSet DS(vertices);
        
        int ans = 0;
        cout << "Following are the edges in the constructed MST\n";

        for (auto edge : edgeList) {
            int weight = edge.first;
            int x = edge.second.first;
            int y = edge.second.second;

            // if x and y don't create a cycle
            if (DS.findParent(x) != DS.findParent(y)) {
                DS.unite(x, y);
                ans += weight;

                cout << "from " << x << " to " << y << " costs " << weight << "\n";
            }
        }

        cout << "Minimum Cost for this Spanning Tree: " << ans;
    }
};


int main() {
    int n;  cin >> n; 
    int vertices = 4;
    Graph g(4);

    while (n--) {
        int w, x, y;
        cin >> w >> x >> y;
        g.addEdge(w, x, y);
    }

    g.kruskalMST();
    return 0;
}