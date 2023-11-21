#include <iostream>
#include<windows.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->data) {//if 'value' is less than 'node->data'
        node->left = insert(node->left, value);
    } else if (value > node->data) {//if 'value' is graeter than 'node->data'
        node->right = insert(node->right, value);
    }

    return node;
}

Node* findMin(Node* node) {
    while (node->left != nullptr) {//as values in left side of tree are smaller always  so it will check all nodes on left 
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* deleteRoot(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty, cannot delete root." <<endl;
        return root;
    }

    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
    } else {
        cout << "Root has children, cannot be deleted using this function." << endl;
        return root;
    }
}

Node* deleteParentWithOneChild(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteParentWithOneChild(root->left, value);
    } else if (value > root->data) {
        root->right = deleteParentWithOneChild(root->right, value);
    } else {
        if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr)) {
            Node* temp = (root->left != nullptr) ? root->left : root->right;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

Node* deleteParentWithTwoChildren(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteParentWithTwoChildren(root->left, value);
    } else if (value > root->data) {
        root->right = deleteParentWithTwoChildren(root->right, value);
    } else {
        if (root->left != nullptr && root->right != nullptr) {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        } else {
            Node* temp = (root->left != nullptr) ? root->left : root->right;
            delete root;
            return temp;
        }
    }
    return root;
}

Node* createBalancedTree() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid input. Number of elements must be greater than 0." << endl;
        return nullptr;
    }

    Node* root = nullptr;

    cout << "Enter " << size << " elements in sorted order: ";
    for (int i = 0; i < size; ++i) {
        int value;
        cin >> value;
        if (i == 0) {
            root = new Node(value);
        } else {
            Node* current = root;
            while (true) {
                if (value < current->data) {
                    if (current->left == nullptr) {
                        current->left = new Node(value);
                        break;
                    } else {
                        current = current->left;
                    }
                } else if (value > current->data) {
                    if (current->right == nullptr) {
                        current->right = new Node(value);
                        break;
                    } else {
                        current = current->right;
                    }
                } else {
                    cout << "Duplicate values are not allowed. Enter a different value: ";
                    cin >> value;
                    current = root;
                }
            }
        }
    }

    return root;
}

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

bool isBalanced(Node* node) {
    if (node == nullptr) {
        return true;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right)) {
        return true;
    }

    return false;
}

void inorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->left);
	cout << node->data << " ";
    inorderTraversal(node->right);
}
void preorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int values[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; ++i) {
        cin >> values[i];
    }

    Node* root = nullptr;

    for (int i = 0; i < size; ++i) {
        root = insert(root, values[i]);
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Pre Order Transversal\n";
        cout << "2. Post Order Transversal Node\n";
        cout << "3. Delete Node\n";
        cout << "4. Delete Parent with One Child\n";
        cout << "5. Delete Parent with Two Children\n";
        cout << "6. Delete Root\n";
        cout << "7. Insert Node\n";
        cout << "8. Create Balanced Tree\n";
        cout << "9. Check if Tree is Balanced\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        	             case 1: {
        // Preorder Traversal
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
        Sleep(2000);
        system("CLS");
        break;
    }
    case 2: {
        // Postorder Traversal
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout <<endl;
        Sleep(2000);
        system("CLS");
        break;
    }
            case 3: {
                int value;
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                cout << "Inorder Traversal after deleting node: ";
                inorderTraversal(root);
                cout <<endl;
                Sleep(2000);
        		system("CLS");
                break;
            }
            case 4: {
                int value;
                cout << "Enter the value to delete (parent with one child): ";
                cin >> value;
                root = deleteParentWithOneChild(root, value);
            	cout << "Inorder Traversal after deleting parent with one child: ";
                inorderTraversal(root);
            	cout << endl;
            	Sleep(2000);
        		system("CLS");
                break;
            }
            case 5: {
                int value;
                cout << "Enter the value to delete (parent with two children): ";
                cin >> value;
                root = deleteParentWithTwoChildren(root, value);
                cout << "Inorder Traversal after deleting parent with two children: ";
                inorderTraversal(root);
                cout << endl;
                Sleep(2000);
        		system("CLS");
                break;
            }
            case 6: {
                root = deleteRoot(root);
                cout << "Inorder Traversal after deleting root: ";
                inorderTraversal(root);
                cout <<endl;
                Sleep(2000);
        		system("CLS");
                break;
            }
            case 7: {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Inorder Traversal after inserting node: ";
                inorderTraversal(root);
                cout << endl;
                Sleep(2000);
        		system("CLS");
                break;
            }
            case 8: {
                // Assuming the values array is sorted
                root = createBalancedTree();
                cout << "Inorder Traversal of the balanced tree: ";
                inorderTraversal(root);
                cout << endl;
                Sleep(2000);
        		system("CLS");
                break;
            }
            case 9: {
                cout << "Is the tree balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;
                Sleep(2000);
        		system("CLS");
                break;
            }
   

            case 10: {
                cout << "Exiting program. Goodbye!\n";
                Sleep(2000);
        		system("CLS");
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                Sleep(2000);
        		system("CLS");
                break;
            }
        }
    } while (choice != 10);

    return 0;
}
