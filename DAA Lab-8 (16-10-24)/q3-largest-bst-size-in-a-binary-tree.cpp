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

class NodeVal {
public:
    int maxNode, minNode, maxSize;

    NodeVal(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

NodeVal findBST(Node* root) {
    if (root == NULL)
        return NodeVal(INT_MAX, INT_MIN, 0);

    auto left = findBST(root->left);
    auto right = findBST(root->right);

    if (left.maxNode < root->key && root->key < right.minNode) {
        return NodeVal(min(root->key, left.minNode), max(root->key, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTsize(Node* root) {
    return findBST(root).maxSize;
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(6);
    root->right = new Node(2);
    // root->left->left = new Node(0);
    root->left->right = new Node(2);
    root->right->left = new Node(1);
    root->right->right = new Node(3);
    // root->left->right->left = new Node(3);
    // root->left->right->right = new Node(5);

    cout << "The size of the BST in this Binary Tree is " << largestBSTsize(root) << endl;

    return 0;
}