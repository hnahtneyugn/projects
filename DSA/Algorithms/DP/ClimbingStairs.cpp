#include <iostream>

using namespace std;

int a[46];

int climbStairs(int n) {
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; ++i)
        a[i] += a[i-1] + a[i-2];
    
    return a[n];
}

int main() {
    cout << climbStairs(5); // 8
    return 0;
}