#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == NULL)
        return root;
    
    if (root->val < low) 
        return trimBST(root->right, low, high);
    
    if (root->val > high)
        return trimBST(root->left, low, high);

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(4);
    
    int low = 1, high = 3;

    root = trimBST(root, low, high);

    // print the tree in pre, in, or post...

    return 0;
}