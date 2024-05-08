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

void insert(Node*& root, int key)
{
    if (root == NULL) {
        root = newNode(key);
        return;
    }

    Node* prev = NULL;
    Node* temp = root;
    while (temp) {
        if (temp->data > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data < key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > key)
        prev->left = newNode(key);
    else
        prev->right = newNode(key);
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
    insert(root, 50);
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