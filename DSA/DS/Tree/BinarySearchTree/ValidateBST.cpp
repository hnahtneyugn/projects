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

bool isValidBST(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* temp = NULL;
    if (root == NULL)
        return true;
    
    // perform inorder traversal
    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
        
        // check if each element is bigger than previous element
        root = s.top();
        s.pop();
        // if true, then it is not a BST
        if (temp != NULL && root->val <= temp->val)
            return false;
        
        temp = root;
        root = root->right;
    }
    
    return true;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout << boolalpha << isValidBST(root);      // should print true
    return 0;
}