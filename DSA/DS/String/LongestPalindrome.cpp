#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int longestPalindrome(string s) {
    string p = s;
    reverse(p.begin(), p.end());
    if (s == p)
        return s.length();

    int sum = 0;
    int odd = 0;
    char t;
    map<char, int> mp;
    for (char& c : s)
        mp[c]++;

    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->second % 2 == 0) {
            sum += itr->second;
        } else {
            if (itr->second > odd) {
                odd = itr->second;
                t = itr->first;
            }
        }
    }

    sum += odd;

    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->second % 2 != 0 && itr->first != t) {
            sum += itr->second - 1;
        }
    }

    return sum;
}

int main() {
    string s = "abccccdd";       // 7
    cout << longestPalindrome(s);

    return 0;
}