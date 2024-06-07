#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string replaceWords(vector<string>& dictionary, string sentence) {
    stringstream ss(sentence);
    string ans = "";
    string word;

    while (ss >> word) {
        for (const string& dict : dictionary) {
            if (word.compare(0, dict.size(), dict) == 0) {
                word = dict;
            }
        }
        if (!ans.empty())
            ans += " ";
        ans += word;
    }

    return ans;
}

int main() {
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";

    cout << replaceWords(dictionary, sentence);     // the cat was rat by the bat

    return 0;
}