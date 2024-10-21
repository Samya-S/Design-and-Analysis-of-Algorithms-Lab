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

Node* insert(Node* node, int val) {
    if (node == NULL)
        return new Node(val);

    if (node->key == val)
        return node;

    if (node->key < val)
        node->right = insert(node->right, val);
    else
        node->left = insert(node->left, val);

    return node;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout << endl;

    return 0;
}