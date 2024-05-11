#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    unordered_map<int, int> mp;
    // size of each bucket
    int bucket_size = valueDiff + 1;
    for (int i = 0; i < nums.size(); ++i) {
        // check which bucket does each element fall into 
        int bucket = nums[i] / bucket_size;
        
        // handle the cases where the bucket might be negative
        if (nums[i] < 0)
                bucket--;
        
        // if current element's bucket is already found
        if (mp.find(bucket) != mp.end())
            return true;        // then it is within the "valueDiff" range;
        
        // do the same with adjacent buckets
        if (mp.find(bucket+1) != mp.end() && abs(mp[bucket+1]-nums[i]) <= valueDiff)
            return true;
        
        if (mp.find(bucket-1) != mp.end() && abs(mp[bucket-1]-nums[i]) <= valueDiff)
            return true;
        
        // so if the current element's bucket is not here, create the bucket
        mp[bucket] = nums[i];
        
        // ensure that every time we check, there is always "indexDiff" buckets in the map
        // remove the redundant bucket, by applying window-sliding technique
        if (i >= indexDiff) {
            // find the bucket to remove
            int bucket_to_erase = nums[i - indexDiff] / bucket_size;
            if (nums[i - indexDiff] < 0)
                bucket_to_erase--;
            mp.erase(bucket_to_erase);
        }
    }
    
    // if no such pair is found throughout the array
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int indexDiff = 3;
    int valueDiff = 0;

    cout << boolalpha << containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);     // true
    return 0;
}