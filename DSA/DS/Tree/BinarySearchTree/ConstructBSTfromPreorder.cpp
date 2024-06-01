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

TreeNode* buildBSTFromPreorder(vector<int>& preorder, int& index, int minVal, int maxVal) {
    if (index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal)
        return NULL;
    
    int val = preorder[index++];
    TreeNode* root = new TreeNode(val);
    root->left = buildBSTFromPreorder(preorder, index, minVal, val);
    root->right = buildBSTFromPreorder(preorder, index, val, maxVal);
    return root;
}
    
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return buildBSTFromPreorder(preorder, index, INT_MIN, INT_MAX);
}

int main() {
    vector<int> v = {8, 5, 1, 7, 10, 12};
    TreeNode* root = bstFromPreorder(v);

    // print the tree in pre, in, or post...

    return 0;
}