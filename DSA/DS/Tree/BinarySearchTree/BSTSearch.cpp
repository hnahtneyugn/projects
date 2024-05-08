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
        return temp;
    } else {
        temp->right = insert(temp->right, key);
        return temp;
    }
}

Node* search(Node* temp, int key) {
    if (temp == NULL || temp->data == key)
        return temp;

    if (temp->data > key)
        return search(temp->left, key);

    return search(temp->right, key);
}

void inorder(Node* temp) {
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // Key to be found
    int key = 6;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        cout << key << " not found\n";
    else
        cout << key << " found\n";
 
    key = 60;
 
    // Searching in a BST
    if (search(root, key) == NULL)
        cout << key << " not found\n";
    else
        cout << key << " found\n";
    return 0;
}