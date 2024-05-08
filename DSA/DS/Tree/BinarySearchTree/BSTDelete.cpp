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

void inorder(Node* temp) {
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

Node* deleteNode(Node* temp, int key) {
    if (temp == NULL)
        return temp;

    if (key < temp->data) {
        temp->left = deleteNode(temp->left, key);
        return temp;
    } else if (key > temp->data) {
        temp->right = deleteNode(temp->right, key);
        return temp;
    }
    
    // Node to be deleted is found

    // if the node has 0 or 1 child
    if (temp->left == NULL) {
        Node* rightChild = temp->right;
        delete temp;
        return rightChild;
    } else if (temp->right == NULL) {
        Node* leftChild = temp->left;
        delete temp;
        return leftChild;
    }
    
    // if the node has 2 children
    // Find the inorder successor (smallest node in the right subtree)
    Node* successorParent = temp;
    Node* successor = temp->right;
    while (successor->left != NULL) {
        successorParent = successor;
        successor = successor->left;
    }
    
    // Copy the data of the inorder successor to the current node
    temp->data = successor->data;

    // Delete the inorder successor
    if (successorParent->left == successor)
        successorParent->left = deleteNode(successor, successor->data);
    else
        successorParent->right = deleteNode(successor, successor->data);

    return temp;
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

    cout << "Original BST: ";
    inorder(root);

    printf("Original BST: ");
    inorder(root);
  
    printf("\n\nDelete a Leaf Node: 20\n");
    root = deleteNode(root, 20);
    printf("Modified BST tree after deleting Leaf Node:\n");
    inorder(root);

    printf("\n\nDelete Node with single child: 70\n");
    root = deleteNode(root, 70);
    printf("Modified BST tree after deleting single child Node:\n");
    inorder(root);

    printf("\n\nDelete Node with both child: 50\n");
    root = deleteNode(root, 50);
    printf("Modified BST tree after deleting both child Node:\n");
    inorder(root);

    return 0;
}