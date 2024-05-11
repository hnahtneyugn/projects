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

bool checkEqual(TreeNode* l, TreeNode* r) {
    // check if left node or right node is null
    if (l == NULL || r == NULL)
        return (l == r);
    // if left node is not equal to right node
    if (l->val != r->val)
        return false;
    // if left node and right node is equal, check its children
    return (checkEqual(l->left, r->right) && checkEqual(l->right, r->left));
}


bool isSymmetric(TreeNode* root) {
    if (root == NULL)
        return true;
    
    return checkEqual(root->left, root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << boolalpha << isSymmetric(root);     // should return true

    return 0;
}