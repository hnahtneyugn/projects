#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // base case
    if (root == NULL)
        return NULL;
    
    // if the node is either equal to p or equal to q
    if (root == p || root == q)
        return root;
    
    // in case the node is not equal to any of them, get the left child and the right child
    TreeNode* leftside = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightside = lowestCommonAncestor(root->right, p, q);
    
    // if both of them are not null, then it means the node with value p and q are found
    // return the parent
    if (leftside != NULL && rightside != NULL)
        return root;
    
    // if the LCA is found in the left side or the right side, return it
    if (leftside != NULL)
        return leftside;
    else
        return rightside;
    
    // return null since the node is not the right one
    return NULL;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(5);
    TreeNode* q = new TreeNode(0);
    cout << lowestCommonAncestor(root, p, q)->val;

    return 0;
}