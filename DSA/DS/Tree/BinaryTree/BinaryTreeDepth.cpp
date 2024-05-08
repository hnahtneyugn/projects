#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL; 

    return node;
}


// recursive function to calculate depth of each node
// depth of a parent = max of depths of its 2 children
int maxDepth(Node* temp) {
    if (temp == NULL)
        return 0;

    int lDepth = maxDepth(temp->left);
    int rDepth = maxDepth(temp->right);

    return 1 + max(lDepth, rDepth);
}

int main() {
    Node* root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Height of tree is " << maxDepth(root);
    return 0;
}