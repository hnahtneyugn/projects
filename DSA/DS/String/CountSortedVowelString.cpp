#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    int n;  cin >> n;
    vector<int> dp(5, 1);
    int sum = 0;

    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 4; j > i; --j) {
                dp[i] += dp[j];
            }
        }
    }
        
    for (int& i : dp) {
        sum += i;
    }

    cout << sum;
    return 0;
}