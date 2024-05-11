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

int calculateHeight(TreeNode* root) {
    // base case
    if (root == NULL)
        return 0;
    
    // calculate height of left child and right child
    int leftChild = calculateHeight(root->left);
    int rightChild = calculateHeight(root->right);

    // -1 means unbalanced
    // if the left/right child is already unbalanced from previous recursive calls
    // or right now they're unbalanced
    // then the current parent node is unbalanced to
    if (leftChild == -1 || rightChild == -1 || abs(leftChild - rightChild) > 1)
        return -1;
    

    // else if the node's children are balanced, calculate the height
    return max(leftChild, rightChild) + 1;
}

bool isBalanced(TreeNode* root) {
    return (calculateHeight(root) != -1);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << boolalpha << isBalanced(root);      // true

    return 0;
}