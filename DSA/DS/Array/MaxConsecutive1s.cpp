#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, maxi;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1)
            ans++;
        else {
            if (ans > maxi)
                maxi = ans;
            ans = 0;
            
        }
    }
    if (ans > maxi)
        maxi = ans;
    
    return maxi;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};      // 3
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}