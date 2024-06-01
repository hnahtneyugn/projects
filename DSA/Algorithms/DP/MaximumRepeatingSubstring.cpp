#include <iostream>
#include <string>

using namespace std;

int maxRepeating(string sequence, string word) {
    int ans = 0;
    string repeating = word;
    while (sequence.find(repeating) != string::npos) {
        ans++;
        repeating += word;
    }
    return ans;
}

int main() {
    string sequence = "ababc";
    string word = "ab";

    cout << maxRepeating(sequence, word);       // 2
    return 0;
}