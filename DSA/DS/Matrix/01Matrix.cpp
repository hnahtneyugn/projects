#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && y >= 0 && x < rows && y < cols);
}


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;

    // Initialize the queue with all zero cells and set their distances to 0
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Directions array to move in 4 possible directions (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto check = q.front();
        q.pop();
        int x = check.first;
        int y = check.second;
        
        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            
            if (isValid(newX, newY, rows, cols) && dist[newX][newY] > dist[x][y] + 1) {
                dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> v = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> ans = updateMatrix(v);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}