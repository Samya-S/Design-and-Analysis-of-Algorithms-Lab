#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int findLeftHeight(Node* node) {
    int h = 0;

    while (node) {
        node = node->left;
        h++;
    }

    return h;
}

int findRightHeight(Node* node) {
    int h = 0;

    while (node) {
        node = node->right;
        h++;
    }

    return h;
}

int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "Total number of nodes in the complete binary tree: " << countNodes(root) << endl;

    return 0;
}