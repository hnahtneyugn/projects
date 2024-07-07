#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        sum %= k;
        if (sum == 0 && i > 0)
            return true;
        if (mp.find(sum) != mp.end() && i - mp[sum] > 1)
            return true;
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return false;
}

int main() {
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    cout << boolalpha << checkSubarraySum(nums, k);     // true
    return 0;
}