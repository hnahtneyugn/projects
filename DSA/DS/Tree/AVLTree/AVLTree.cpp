#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// create a new Node
Node* newNode(int data) {
    Node* node = new Node();
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// get height of a tree
int getHeight(Node* temp) {
    if (temp == NULL)
        return 0;
    
    return temp->height;
}

// get the balance of a node (height of left subtree - height of right subtree)
int getBalance(Node* temp) {
    if (temp == NULL)
        return 0;
    
    return getHeight(temp->left) - getHeight(temp->right);
}

// function to rotate left
//     x                  y
//       \      ->      /   
//         y          x
Node* rotateLeft(Node* x) {
    // rotate to the left
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    // update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // return new root
    return y;
}

// function to rotate right
//         x           y
//       /      ->      \
//     y                  x
Node* rotateRight(Node* x) {
    // rotate to the right
    Node* y = x->left;
    Node* temp = y->right;

    y->right = x;
    x->left = temp;
    
    // update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // return new root
    return y;
}


// inserting a new Node into the AVL Tree
Node* insert(Node* root, int data) {
    // if root is null, create a new Node
    // normal BST Insertion
    if (root == NULL)
        return newNode(data);
    if (root->key > data)
        root->left = insert(root->left, data);
    else if (root->key < data)
        root->right = insert(root->right, data);

    // update the height of the ancestor (nodes which are not newly inserted)
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // get the balance of the node
    int balance = getBalance(root);

    // in case the tree is now not balanced, there are 4 cases
    // LEFT-LEFT case
    if (balance > 1 && data < root->left->key) 
        return rotateRight(root);

    // RIGHT-RIGHT case
    if (balance < -1 && data > root->right->key)
        return rotateLeft(root);
    
    // LEFT-RIGHT case
    if (balance > 1 && data > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RIGHT-LEFT case
    if (balance < -1 && data < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // if the balance factor is not affected
    // return the ancestor node
    return root;
}

// deleting a Node from the AVL Tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;
    
    if (data < root->key)
        root->left = deleteNode(root->left, data);
    else if (data > root->key)
        root->right = deleteNode(root->right, data);
    else {
        // here, the node to be deleted is found
    // if the node has 0 or 1 child
    if (root->left == NULL) {
        Node* rightChild = root->right;
        delete root;
        return rightChild;
    } else if (root->right == NULL) {
        Node* leftChild = root->left;
        delete root;
        return leftChild;
    }

    // if the node has 2 children
    // case of 2 children in a node
    Node* father = root;
    Node* child = root->right;
    while (child->left != NULL) {
        father = child;
        child = child->left;
    }
    
    root->key = child->key;
    
    // connect the separated subtree
    // the child node (inorder successor), might lay on the left or right side of the father
    // so we have to connect father to the remaining part of the BST, a.k.a the "child->right"
    if (father->left == child)
        father->left = child->right;
    else
        father->right = child->right;
    }
         
    // update the height of the ancestor (nodes which are not newly inserted)
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // get the balance of the node
    int balance = getBalance(root);

    // if the ancestor node is now unbalanced, there are 4 cases
    // LEFT-LEFT case
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rotateRight(root); 

    // RIGHT-RIGHT case 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return rotateLeft(root); 
 
    // LEFT-RIGHT case 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left = rotateLeft(root->left); 
        return rotateRight(root); 
    } 
 
    // RIGHT-LEFT case 
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rotateRight(root->right); 
        return rotateLeft(root); 
    } 
 
    return root;

}

int main() {
    Node *root = NULL; 
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 

    cout << "Preorder traversal of the constructed AVL tree is \n"; 
    inorder(root); 
 
    root = deleteNode(root, 10); 

    cout << "\nPreorder traversal after deletion of 10 \n"; 
    inorder(root); 
 
    return 0; 
}