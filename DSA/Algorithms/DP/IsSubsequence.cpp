#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < t.length()) {
        if (t[i] == s[j])
            j++;
        
        i++;
    }
    if (j == s.length())
        return true;
    else
        return false;
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    cout << boolalpha << isSubsequence(s, t);       // true
    return 0;
}