#include <iostream>
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

// simply use a temp node to be the new node and attach each node to the right of it
TreeNode* temp = new TreeNode();
TreeNode* tourist = temp;
void traverse(TreeNode* root) {
    stack<TreeNode*> s;
    while(root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        TreeNode* curr = s.top();
        s.pop();
        tourist->right = new TreeNode(curr->val);
        tourist = tourist->right;
        root = curr->right;
    }
}

TreeNode* increasingBST(TreeNode* root) {
    traverse(root);
    return temp->right;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    TreeNode* temp = increasingBST(root);
    return 0;
}