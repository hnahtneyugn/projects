#include <iostream>
#include <queue>

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


// increase depth when the level increases
// insert child nodes of next level and pop nodes of previous level
int maxDepth(Node* root) {
    queue<Node*> q;
    q.push(root);
    int depth = 0;

    while(!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            if (temp->left != NULL) {
                q.push(temp->left);
            }

            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        depth++;
    }

    return depth;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    cout << "Height(Depth) of tree is: " << maxDepth(root);
}