#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> dp;
    for (int i = 0; i < numRows; ++i)
        dp.push_back(vector<int>(0));

    for (int m = 0; m < numRows; ++m) {
        for (int n = 0; n <= m; ++n) {
            if (n == 0 || n == m)
                dp[m].push_back(1);
            else    
                dp[m].push_back(dp[m-1][n-1] + dp[m-1][n]);
        }
    }
    return dp;
}

int main() {
    vector<vector<int>> v = generate(5);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}