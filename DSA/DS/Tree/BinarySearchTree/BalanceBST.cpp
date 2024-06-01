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

vector<int> inorder;
void traversal(TreeNode* root) {
    stack<TreeNode*> s;
    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        TreeNode* temp = s.top();
        s.pop();
        inorder.push_back(temp->val);
        root = temp->right;
    }
}

TreeNode* build(vector<int>& inorder, int l, int r) {
    if (l > r)
        return NULL;
    
    int mid = l + (r - l)/2;
    TreeNode* node = new TreeNode(inorder[mid]);
    if (l == r)
        return node;
    
    node->left = build(inorder, l, mid - 1);
    node->right = build(inorder, mid + 1, r);

    return node;
}

TreeNode* balanceBST(TreeNode* root) {
    traversal(root);
    return build(inorder, 0, inorder.size()-1);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    TreeNode* temp = balanceBST(root);

    // print the tree in pre, in, or post...

    return 0;
}