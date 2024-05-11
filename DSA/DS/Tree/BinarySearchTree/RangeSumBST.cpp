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
void traverse(TreeNode* root, int low, int high) {
    stack<TreeNode*> s;
    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }

        TreeNode* temp = s.top();
        s.pop();
        if (low <= temp->val && temp->val <= high)
            sum += temp->val;
        root = temp->right;
    }
}


int rangeSumBST(TreeNode* root, int low, int high) {
    traverse(root, low, high);
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    int low = 7, high = 15;

    cout << rangeSumBST(root, low, high);       // 32
    return 0;
}