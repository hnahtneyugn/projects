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

TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int& index) {
    // base case
    if (l > r)
        return NULL;
    
    // get the last element from postorder and create a node with its value
    TreeNode* newNode = new TreeNode(postorder[index]);
    index--;
    
    // if there is only one element, then build the node
    if (l == r)
        return newNode;
    
    // get the index of this node
    // recursively build the left and right children of this node

    int mid = mp[newNode->val];
    newNode->right = build(inorder, postorder, mid + 1, r, index);
    newNode->left = build(inorder, postorder, l, mid - 1, index);
    
    return newNode;
}

// use map to attach each element in inorder to its index
void makemap(vector<int>& inorder, unordered_map<int, int>& mp) {
    for (int i = 0; i < inorder.size(); ++i) 
        mp[inorder[i]] = i;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    makemap(inorder, mp);
    int n = postorder.size();
    int k = n - 1;
    return build(inorder, postorder, 0, inorder.size()-1, k);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTree(inorder, postorder);
    
    return 0;
}