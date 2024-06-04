#include <iostream>
#include <string>

using namespace std;

int appendCharacters(string s, string t) {
    int i = 0, j = 0;
    while (i < s.length()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else
            i++;
    }

    return t.length()-j; 
}

int main() {
    string s = "coaching", t = "coding";
    
    cout << appendCharacters(s, t);         // 4
    return 0;
}