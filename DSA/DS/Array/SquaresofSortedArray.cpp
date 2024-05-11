#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for (int num : nums)
        num = num * num;
    
    vector<int> v(nums.size());

    int l = 0;
    int r = nums.size() - 1;
    int curr = r;
    
    while (l <= r) {
        if (abs(nums[l]) > abs(nums[r])) {
            v[curr] = nums[l] * nums[l];
            l++;
        } else {
            v[curr] = nums[r] * nums[r];
            r--;
        }
        
        curr--;
    }
    
    return v;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ans = sortedSquares(nums);

    for (int i  : ans)
        cout << i << " ";
    
    return 0;
}