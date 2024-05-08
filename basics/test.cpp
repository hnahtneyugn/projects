#include <iostream>

using namespace std;

long long arr[51];

long long fib(int n) {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];
}

int main() {
    cout << fib(5) << "\n";
    cout << fib(50);
    return 0;
}