#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find the smallest element in the right side of each element
void selection_sort(vector<int>& v) {
    for (int i = 0; i < v.size()-1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min_idx])
                min_idx = j;
        }

        if (min_idx != i) {
            swap(v[i], v[min_idx]);
        }
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
    selection_sort(arr);
    cout << "Array after sorting:\n";
    print(arr);
}