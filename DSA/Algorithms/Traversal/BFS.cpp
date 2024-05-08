#include <iostream>

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

int maxDepth(Node* temp) {
    if (temp == NULL)
        return 0;

    int lDepth = maxDepth(temp->left);
    int rDepth = maxDepth(temp->right);

    return 1 + max(lDepth, rDepth);
}

void BFSforHeight(Node* temp, int level) {
    if (temp == NULL) 
        return;
    
    if (level == 1) {
        cout << temp->data << " ";
    } else if (level > 1) {
        BFSforHeight(temp->left, level - 1);
        BFSforHeight(temp->right, level - 1);
    }
}

void BFS(Node* root) {
    int h = maxDepth(root);

    for (int i = 1; i <= h; i++)
        BFSforHeight(root, i);
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    BFS(root);
 
    return 0;
}