#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// get the partition point
int partition(vector<int>& v, int low, int high) {
    // choose a pivot point (low, high, middle, random,...)
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j <= high; ++j) {
        if (v[j] < pivot) {
            i++;
            swap(v[j], v[i]);
        }
    }

    // put the pivot (in this case v[high], to the right position)
    swap(v[i+1], v[high]);
    return (i + 1);
    // return the position of the pivot
}

// recursive call with subarrays on the left side and right side of partition point
void quick_sort(vector<int>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quick_sort(v, low, pi-1);
        quick_sort(v, pi + 1, high);
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
    quick_sort(arr, 0, arr.size()-1);
    cout << "Array after sorting:\n";
    print(arr);
}