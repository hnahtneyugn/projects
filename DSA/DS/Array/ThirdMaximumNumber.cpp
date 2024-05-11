#include <iostream>
#include <vector>
#include <set>

using namespace std;

int thirdMax(vector<int>& nums) {
    // use set to remove duplicates
    set<int> s;
    for (int num : nums)
        s.insert(num);
    
    if (s.size() < 3)
        return *s.rbegin();
    
    set<int>::iterator it = s.begin();
    advance(it, s.size()-3);
    return *it;
}

int main() {
    vector<int> v = {2, 2, 3, 1};
    cout << thirdMax(v);            // 1

    return 0;
}