#include <iostream>

using namespace std;

int a[38];

int tribonacci(int n) {
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= n; ++i) {
        a[i] += a[i-1] + a[i-2] + a[i-3];
    }

    return a[n];
}

int main() {
    cout << tribonacci(25);     // 1389537
    return 0;
}