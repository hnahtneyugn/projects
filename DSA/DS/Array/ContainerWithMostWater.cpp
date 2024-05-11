#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    vector<int> ans;
    int i = 0, j = height.size()-1;
    
    // use two-pointer technique to calculate the area
    // for each area, only opt for the higher line
    // because there is absolutely no good in choosing the shorter ones
    while(i < height.size()-1 && j > 0 && i != j) {
        int temp = min(height[i], height[j]);
        ans.push_back(temp * (j - i));

        if (height[i] < height[j])  i++;
        else                        j--;
    }

    return *max_element(ans.begin(), ans.end());
}

int main() {
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(v);             // 49

    return 0;
}