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

int sum = 0;

// inverted inorder traversal
void invertedInorder(TreeNode* root) {
    TreeNode* curr = root;
    stack<TreeNode*> s;
    while (curr != NULL || !s.empty()) {
        while(curr != NULL) {
            s.push(curr);
            curr = curr->right;
        }
    TreeNode* temp = s.top();
    s.pop();
    int hold = temp->val;
    temp->val += sum;
    sum += hold;
    curr = temp->left;
    }
}

TreeNode* bstToGst(TreeNode* root) {
    invertedInorder(root);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    TreeNode* temp = bstToGst(root);
    return 0;
}