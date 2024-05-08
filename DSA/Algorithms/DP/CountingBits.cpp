#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n+1);
    for (int i = 0; i < n+1; ++i) {
        ans[i] = ans[i/2] + (i%2);
    }
    return ans;
}

int main() {
    vector<int> v = countBits(16);
    for (int i : v)
        cout << i << " ";
    return 0;
}