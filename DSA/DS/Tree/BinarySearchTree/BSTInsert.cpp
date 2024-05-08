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

Node* insert(Node* temp, int key) {
    if (temp == NULL)
        return newNode(key);

    if (key < temp->data) {
        temp->left = insert(temp->left, key);
    } else {
        temp->right = insert(temp->right, key);
    }
}

void inorder(Node* temp) {
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Print inorder traversal of the BST
    inorder(root);
 
    return 0;
}