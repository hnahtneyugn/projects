#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < nums.size(); ++i) {
    if (const auto it = numToIndex.find(target - nums[i]);
        it != numToIndex.cend())
        return {it->second, i};
        numToIndex[nums[i]] = i;
    }

    throw;
}

int main() {
    vector<int> nums = {3, 2 ,4};
    int target = 6;
    
    for (int& i : twoSum(nums, target)) 
        cout << i << " ";                       // 0 1

    return 0;
}