#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0)
        return false;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> mp;

    for (const int& i : hand) {
        mp[i]++;
    }

    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        pq.push(itr->first);
    }

    while (!pq.empty()) {
        int t = pq.top();
        for (int i = t; i < t + groupSize; ++i) {
            if (mp.find(i) == mp.end())
                return false;

            mp[i]--;
            if (mp[i] == 0) {
                if (i != pq.top())
                    return false;
                pq.pop();
            }
        }
    }
    
    return true;
}

int main() {
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;

    cout << boolalpha << isNStraightHand(hand, groupSize);      // true
    return 0;
}