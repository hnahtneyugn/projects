#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// print nodes inorder sequences
void inorder(Node* temp) {
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL; 

    return node;
}


// BFS traversal
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL) {
            q.push(temp->left); 
        } else {
            temp->left = newNode(data);
            return root;
        }

        if (temp->right != NULL) {
            q.push(temp->right); 
        } else {
            temp->right = newNode(data);
            return root;
        }
    }

    return root;
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = insertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
 
    return 0;
}