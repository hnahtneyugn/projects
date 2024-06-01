#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int scoreOfString(string s) {
    int sum = 0;
    for (int i = 1; i < s.length(); ++i) {
        sum += abs((int)s[i] - (int)s[i-1]);
    }

    return sum;
}

int main() {
    string s = "hello";
    cout << scoreOfString(s);       // 13;

    return 0;
}