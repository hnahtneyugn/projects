#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<int> table;
    int tablesize;

public:
    // construct hash table
    HashTable(int size) {
        this->tablesize = size;
        table.resize(tablesize, -1);
    }

    // find the result of the hash function
    int hashFunction(int x) {
        return (x % tablesize);
    }

    // insert a new item to the hash table
    void insertItem(int x) {
        // find index by the hash function
        int index = hashFunction(x);

        // if there is already another key at that index, move to the adjacent key
        while (table[index] != x && table[index] != -1) {
            index = (index + 1) % tablesize;
        }

        // upon finding an empty index, put the new key in
        if (table[index] != x)
            table[index] = x;
    }

    void deleteItem(int x) {
        // find index by the hash function
        int index = hashFunction(x);

        // traverse all indexes with key inside 
        while (table[index] != -1) {
            if (table[index] == x) {
                table[index] = -1;
                return;
            }
            index = (index + 1) % tablesize;
        }
    }

    int searchItem(int x) {
        int index = hashFunction(x);
        int counter = 0;

        while(table[index] != -1 && counter != table.size()) {
            if(table[index] == x) {
                return index;
            }
        index = (index + 1) % table.size();
        counter++;
        }
        return -1;
    }

    // print the hash table
    void printHash() {
        for (int i = 0; i < table.size(); ++i) {
            cout << i << " ---> ";
            if (table[i] != -1)
                cout << table[i] << "\n";
            else
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
    cout << h.searchItem(15) << "\n";
    h.printHash();

    return 0;
}