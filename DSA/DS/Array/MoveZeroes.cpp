#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    // j is index of elements that are moved to the front
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> v = {0, 1, 0, 3, 12};
    moveZeroes(v);

    for (int i : v)
        cout << i << " ";

    return 0;
}