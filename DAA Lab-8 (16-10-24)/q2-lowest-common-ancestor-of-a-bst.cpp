#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) {
        key = val;
        left = NULL;
        right = NULL;
    }
};

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL || root == p || root == q)
        return root;

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    Node* p = root->left;
    Node* q = root->right;

    Node* lca = lowestCommonAncestor(root, p, q);

    cout << "The lca of " << p->key << " and " << q->key << " is " << lca->key << endl;

    return 0;
}