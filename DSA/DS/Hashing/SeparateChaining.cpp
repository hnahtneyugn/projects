#include <iostream>
#include <vector>

using namespace std;

class HashTable{
private:
    int tablesize;
    vector<vector<int>> table;

public:
    // initializer list
    HashTable(int size) : tablesize(size), table(size) {}

    // find the result of the hash function
    int hashFunction(int x) {
        return (x % tablesize);
    }

    // insert a new item to the hash table
    void insertItem(int x) {
        // find index by hash function
        int index = hashFunction(x);
        // push the element into the corresponding block
        table[index].push_back(x);
    }  

    // find the item to delete from the hash table
    void deleteItem(int x) {
        // find index by hash function
        int index = hashFunction(x);

        vector<int>::iterator itr;
        for (itr = table[index].begin(); itr != table[index].end(); ++itr) {
            if (*itr == x)
                break;
        }

        if (itr != table[index].end())
            table[index].erase(itr);
    }

    // print the hash table
    void printHash() {
        for (int i = 0; i < tablesize; ++i) {
            cout << i;
            for (int duplicateElements : table[i]) {
                cout << " ---> " << duplicateElements;
            }
            cout << "\n";
        }
    }

};

int main() {
    vector<int> test = {15, 11, 27, 8, 12};

    HashTable h(7);
    for (int i = 0; i < test.size(); ++i) 
        h.insertItem(test[i]);
    
    h.deleteItem(12);
    h.printHash();

    return 0;
}