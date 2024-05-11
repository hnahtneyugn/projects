#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> v;
int totalmin = INT_MAX;
int findMin(vector<int>& v) {
    for (int i = 0; i < v.size()-1; ++i) {
        totalmin = min(totalmin, v[i+1] - v[i]);
    } 
    return totalmin;
}

int getMinimumDifference(TreeNode* root) {
    stack<TreeNode*> s;
    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        TreeNode* temp = s.top();
        s.pop();
        v.push_back(temp->val);
        root = temp->right;
    }

    return findMin(v);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << getMinimumDifference(root);         // 1
    return 0;
}