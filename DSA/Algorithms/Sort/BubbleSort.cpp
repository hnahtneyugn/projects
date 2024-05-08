#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble_sort(vector<int>& v) {
    for (int i = 0; i < v.size()-1; ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i] > v[j])
                swap(v[i], v[j]);
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
    bubble_sort(arr);
    cout << "Array after sorting:\n";
    print(arr);
}