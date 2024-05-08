#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& v, int low, int mid, int high) {
    int lenA = mid - low + 1;
    int lenB = high - mid;

    // create dynamic arrays
    int* arrayA = new int[lenA];
    int* arrayB = new int[lenB];

    // copy elements to dynamic arrays
    for (int i = 0; i < lenA; ++i)
        arrayA[i] = v[low + i];
    for (int j = 0; j < lenB; ++j)
        arrayB[j] = v[(mid + 1) + j];

    // insert elements to the original array
    int i = 0, j = 0, vectorIndex = low;
    while (i < lenA && j < lenB) {
        if (arrayA[i] < arrayB[j])
            v[vectorIndex++] = arrayA[i++];
        else 
            v[vectorIndex++] = arrayB[j++];
    }
    
    // insert the remaining elements of either arrayA or arrayB
    while (i < lenA) 
        v[vectorIndex++] = arrayA[i++];

    while (j < lenB)
        v[vectorIndex++] = arrayB[j++];

    delete[] arrayA;
    delete[] arrayB;
}

// recursive call with subarrays on the left side and right side of partition point
void merge_sort(vector<int>& v, int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2;
        merge_sort(v, low, mid);
        merge_sort(v, mid+1, high);
        merge(v, low, mid, high);
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
    merge_sort(arr, 0, arr.size()-1);
    cout << "Array after sorting:\n";
    print(arr);
}