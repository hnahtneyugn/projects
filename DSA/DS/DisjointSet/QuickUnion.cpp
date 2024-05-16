#include <iostream>

using namespace std;

class QuickUnionUF {
    private: 
        int* id;
        int size;

    public:
        QuickUnionUF(int n) {
            id = new int[n];
            this->size = n;
            for (int i = 0; i < size; ++i) {
                id[i] = i;
            }
        }

        ~QuickUnionUF() {
        delete[] id; // Free memory allocated for id
        }        

        int root(int i) {
            while (i != id[i]) {
                i = id[i];
            }

            return i;
        }

        bool connected(int p, int q) {
            return (root(p) == root(q));
        }

        void unionn(int p, int q) {
            int i = root(p);
            int j = root(q);
            id[i] = j;
        }  

        int* getID() {
            return this->id;
        }      
};

int main() {
    int size = 10;
    QuickUnionUF uf(size);
    uf.unionn(4, 3);
    uf.unionn(3, 8);
    uf.unionn(6, 5);
    uf.unionn(9, 4);
    uf.unionn(2, 1);
    uf.connected(8, 9);
    uf.connected(5, 4);
    uf.unionn(5, 0);
    uf.unionn(7, 2);
    uf.unionn(6, 1);
    uf.unionn(7, 3);

    int* testID = uf.getID();
    for (int i = 0; i < size; ++i) {
        cout << testID[i] << " ";
    }

    return 0;
}