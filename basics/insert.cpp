#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int depth(vector<vector<int>>& v, int index) {
    int n = v[index].size();
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1 + depth(v, v[index][0]);
    } else {
        return 1 + max(depth(v, v[index][0]), depth(v, v[index][1]));
    }
}

bool check(vector<vector<int>>& v, int index) {
    int n = v[index].size();
    if (n == 0) {
        return true;
    } else if (n == 1) {
        if (abs(depth(v, v[index][0]) - (-1)) <= 1 && check(v, v[index][0]))
            return true;
    } else {
        if (abs(depth(v, v[index][0]) - depth(v, v[index][1])) <= 1 && check(v, v[index][0]) && check(v, v[index][1]))
            return true;
    }

    return false;
}

int main() {   
    int n;  cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;   cin >> x >> y;
        v[x].push_back(y);
    }

    depth(v, 0);
    if (check(v, 0)) {
        cout << "yes";
    } else {
        cout << "no";
    }
    
	return 0;
}