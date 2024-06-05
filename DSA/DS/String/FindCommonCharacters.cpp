#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    vector<string> ans;
    unordered_map<char, int> mp;

    for (const char& c : words[0])
        mp[c]++;
    
    for (int i = 1; i < words.size(); ++i) {
        unordered_map<char, int> temp;
        for (const char& c : words[i])
            temp[c]++;
        
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) { 
            mp[itr->first] = min(mp[itr->first], temp[itr->first]);
        }
    }
        
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) 
        for (int i = 0; i < itr->second; ++i)
            ans.push_back(string(1, itr->first));

    return ans;
}

int main() {
    vector<string> words = {"bella", "label", "roller"};
    for (const string& i : commonChars(words)) 
        cout << i << " ";
    
    return 0;
}