#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// to heapify (a.k.a modify the heap perfectly) at the node with index i
// the heap size is n, which means the node comes from index 0 to n
void heapify(vector<int>& v, int n, int i) {
    // initialize the root as the largest
    int largest = i;

    // left child, right child
    int leftindex = 2*i + 1, rightindex = 2*i + 2;

    // if left child > root, left child is now largest
    if (leftindex < n && v[leftindex] > v[i])
        largest = leftindex;
    
    // if right child > largest, right child is now largest
    if (rightindex < n && v[rightindex] > v[largest])
        largest = rightindex;

    // if largest is not root, then one of the two children is bigger than its parent
    // swap that children with the parent
    // heapify the affected subtree, with the subtree's root is the children node (a.k.a largest)
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

// main heapsort function
void heapSort(vector<int>& v, int n) {
    // before sorting, heapify the tree
    // only need to heapify the upper half to avoid repetition
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(v, n, i);
    
    // after heapifying the whole tree, begin to sort elements in-place
    // move the largest element (maxheap) to the end of the array
    // then heapify for the rest of the heap, starting from node 0
    for (int i = n - 1; i > 0; --i) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

// print all elements in the vector
void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
}

int main() {
    vector<int> v = {12, 20, 5, 9, 15, 7};
    heapSort(v, v.size());

    cout << "Vector after sorting:\n";
    printVector(v);

    return 0;
}