#include <iostream>
#include <stack>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

set<int> myset;
bool findTarget(TreeNode* root, int k) {
    stack<TreeNode*> s;
    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        TreeNode* temp = s.top();
        s.pop();
        
        // insert the node into the set
        myset.insert(temp->val);
        
        // if the counterpart is also found and different from the node
        // return true, otherwise insert the counterpart into the set
        if (myset.find(k-temp->val) != myset.end() && temp->val != k-temp->val)
            return true;
        else
            myset.insert(k-temp->val);
        root = temp->right;
    }

    return false;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    int k = 7;

    cout << boolalpha << findTarget(root, k);       // true
    return 0;
}