#include <iostream>
#include <queue>

using namespace std;
 
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (root == NULL)
        return root;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        
        // pushing levels of nodes sequentially
        // for each level, point each node to the next node
        // if the node is the last one of its level, point it to null

        for (int i = 0; i < n; ++i) {
            Node* temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            if (i == n-1)
                temp->next = NULL;
            else
                temp->next = q.front();
        }
    }
    
    return root;
}

int main() {
    Node* root = connect(root);

    return 0;
}