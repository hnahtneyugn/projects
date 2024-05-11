#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] % 2 == 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
    
    return nums;
}

int main() {
    vector<int> v = {0, 1, 0, 3, 12};
    vector<int> ans = sortArrayByParity(v);

    for (int i : ans)
        cout << i << " ";

    return 0;
}