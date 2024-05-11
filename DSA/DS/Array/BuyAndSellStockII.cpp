#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    vector<int> differences(prices.size()-1);

    // calculate differences
    for (int i = 0; i < prices.size()-1; ++i) {
        differences[i] = prices[i+1] - prices[i];
    }

    // only take differences which are > 0
    for (int difference : differences) 
        if (difference > 0)
            ans += difference;

    return ans;
}

int main() {
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(v);                   // 7

    return 0;
}