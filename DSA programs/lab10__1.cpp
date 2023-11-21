#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(height(node->left), height(node->right)) + 1;
}

bool isBalanced(Node* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int n, value;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insertNode(root, value);
    }

    if (isBalanced(root)) {
        cout << "The tree is balanced.\n";
    } else {
        cout << "The tree is not balanced.\n";
    }

    return 0;
}
