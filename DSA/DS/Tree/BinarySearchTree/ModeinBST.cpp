#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

map<int, int> mp;
vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> s;
    while(root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        TreeNode* temp = s.top();
        s.pop();
        mp[temp->val]++;
        root = temp->right;
    }
    int maxShown = -1;

    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->second > maxShown) {
            maxShown = itr->second;
        }
    }

    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->second == maxShown)
            ans.push_back(itr->first);
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    vector<int> v = findMode(root);
    for (int i : v)
        cout << i << " ";               // 2
    
    return 0;
}