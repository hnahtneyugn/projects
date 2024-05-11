#include <iostream>
#include <unordered_map>
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

unordered_map<int, int> mp;

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r, int& index) {
    if (l > r)
        return NULL;
    
    // get the first element from preorder and create a node with its value
    TreeNode* newNode = new TreeNode(preorder[index]);
    index++;

    // if there is only one element, then build the node  
    if (l == r)
        return newNode;
    
    // get the index of this node
    // recursively build the left and right children of this node
    
    int mid = mp[newNode->val];
    newNode->left = build(preorder, inorder, l, mid - 1, index);
    newNode->right = build(preorder, inorder, mid + 1, r, index);
    
    return newNode;
}

// use map to attach each element in inorder to its index
void makemap(vector<int>& inorder, unordered_map<int, int>& mp) {
    for (int i = 0; i < inorder.size(); ++i)
        mp[inorder[i]] = i;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    makemap(inorder, mp);
    int n = 0;
    return build(preorder, inorder, 0, inorder.size()-1, n);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    makemap(inorder, mp);
    int n = 0;
    return build(preorder, inorder, 0, inorder.size()-1, n);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    TreeNode* root = buildTree(preorder, inorder);
    
    return 0;
}