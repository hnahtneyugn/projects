#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxi = prices[0];
    int ans = 0;
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < maxi)
            maxi = prices[i];
        
        ans = max(ans, prices[i] - maxi);
    }

    return ans;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);      // 5

    return 0;
}