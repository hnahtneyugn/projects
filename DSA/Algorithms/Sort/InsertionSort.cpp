#include <iostream>
#include <vector>

using namespace std;

// pull larger elements up 1 position
void insertion_sort(vector<int>& v) {
    int key, j;
    for (int i = 1; i < v.size(); ++i) {
        key = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void print(vector<int> & v) {
    for (int ele : v) 
        cout << ele << " ";

    cout << "\n";
}

int main() {
    vector<int> arr = {1, 23, 10, 5, 12};
    cout << "Array before sorting:\n";
    print(arr);
    insertion_sort(arr);
    cout << "Array after sorting:\n";
    print(arr);
}