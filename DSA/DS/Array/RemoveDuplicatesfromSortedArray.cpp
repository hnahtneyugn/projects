#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int j = 0, temp = nums[0], ans = 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != temp) {
            temp = nums[i];
            nums[j+1] = temp;
            j++;
            ans++;
        }
    }
    
    return ans;
}

int main() {
    vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout <<  removeDuplicates(v);       // 5

    return 0;
}