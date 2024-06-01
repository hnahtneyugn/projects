#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    for (int i = cost.size() - 3; i >= 0; i--) {
        cost[i] += min(cost[i+1], cost[i+2]);
    }

    return min(cost[0], cost[1]);
}

int main() {
    vector<int> cost = {5, 10, 15, 20};
    cout << minCostClimbingStairs(cost);     // 20

    return 0;
}