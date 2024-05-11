#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

unordered_map<int, Node*> mp;

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL; 

    return node;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    Node* prev = NULL;
    Node* temp = root;
    while (temp) {
        if (temp->data > data) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data < data) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > data)
        prev->left = newNode(data);
    else
        prev->right = newNode(data);
    
    mp[data] = prev;
    return root;
} 

int main() {
    Node* root = NULL;
    int n;  cin >> n;
    int a[n];
    vector<int> parent;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        root = insertNode(root, a[i]);
    }
    
    for (int i = 1; i < n; ++i) {
        parent.push_back(mp[a[i]]->data);
    }

    for (int i : parent)
        cout << i << " ";

    return 0;
}