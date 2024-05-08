#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> dp;
    for (int i = 0; i < rowIndex+1; ++i)
        dp.push_back(vector<int>(0));

    for (int m = 0; m < rowIndex+1; ++m) {
        for (int n = 0; n <= m; ++n) {
            if (n == 0 || n == m)
                dp[m].push_back(1);
            else    
                dp[m].push_back(dp[m-1][n-1] + dp[m-1][n]);
        }
    }
    return dp[rowIndex];
}


int main() {
    vector<int> ans = getRow(3);
    for (int i : ans)
        cout << i << " ";
    return 0;
}