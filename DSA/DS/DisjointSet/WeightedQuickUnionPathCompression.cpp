#include <iostream>

using namespace std;

class WeightedQuickUnionPathCompressionUF {
private:
    int* id;
    int* sz; // Change from int sz[] to int* sz
    int size;

public:
    WeightedQuickUnionPathCompressionUF(int n) {
        id = new int[n];
        sz = new int[n]; // Allocate memory for sz
        this->size = n;
        for (int i = 0; i < size; ++i) {
            id[i] = i;
            sz[i] = 1; // Initialize sz
        }
    }

    ~WeightedQuickUnionPathCompressionUF() {
        delete[] id; // Free memory allocated for id
        delete[] sz; // Free memory allocated for sz
    }

    int root(int i) {
        while (i != id[i]) {
            int temp = id[i];
            id[i] = id[id[i]];
            i = temp;
        }
        return i;
    }

    bool connected(int p, int q) {
        return (root(p) == root(q));
    }

    void unionn(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j)
            return;

        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
    }

    int* getID() {
        return this->id;
    }
};

int main() {
    int size = 10;
    WeightedQuickUnionPathCompressionUF wuf(size);
    wuf.unionn(4, 3);
    wuf.unionn(3, 8);
    wuf.unionn(6, 5);
    wuf.unionn(9, 4);
    wuf.unionn(2, 1);
    wuf.connected(8, 9);
    wuf.connected(5, 4);
    wuf.unionn(5, 0);
    wuf.unionn(7, 2);
    wuf.unionn(6, 1);
    wuf.unionn(7, 3);

    int* testID = wuf.getID();
    for (int i = 0; i < size; ++i) {
        cout << testID[i] << " ";
    }

    return 0;
}