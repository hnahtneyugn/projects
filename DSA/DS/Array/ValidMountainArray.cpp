#include <iostream>
#include <vector>

using namespace std;

// use two-pointer technique
// while traversing from both sides, if the two pointers meet, then it is valid
// otherwise, not valid
bool validMountainArray(vector<int>& arr) {
    int i = 0, j = arr.size() - 1;
    while (i < arr.size() - 1 && arr[i] < arr[i+1])
        i++;
    
    while (j > 0 && arr[j] < arr[j - 1])
        j--;
        
    return (i == j && i > 0 && j < arr.size()-1);
    
}

int main() {
    vector<int> v = {0, 3, 2, 1};
    cout << boolalpha << validMountainArray(v);         // true

    return 0;
}