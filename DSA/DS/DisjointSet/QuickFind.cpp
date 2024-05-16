#include <iostream>

using namespace std;

class QuickFindUF {
    private: 
        int* id;
        int size;

    public:
        QuickFindUF(int n) {
            id = new int[n];
            this->size = n;
            for (int i = 0; i < size; ++i) {
                id[i] = i;
            }
        }

        ~QuickFindUF() {
        delete[] id; // Free memory allocated for id
        }

        bool connected(int p, int q) {
            return (id[p] == id[q]);
        }

        void unionn(int p, int q) {
            int pid = id[p];
            int qid = id[q];
            for (int i = 0; i < this->size; ++i) {
                if (id[i] == pid)
                    id[i] = qid;
            }
        }  

        int* getID() {
            return this->id;
        }      
};

int main() {
    int size = 10;
    QuickFindUF qf(size);
    qf.unionn(4, 3);
    qf.unionn(3, 8);
    qf.unionn(6, 5);
    qf.unionn(9, 4);
    qf.unionn(2, 1);
    qf.connected(8, 9);
    qf.connected(5, 0);
    qf.unionn(5, 0);
    qf.unionn(7, 2);
    qf.unionn(6, 1);

    int* testID = qf.getID();
    for (int i = 0; i < size; ++i) {
        cout << testID[i] << " ";
    }

    return 0;
}