#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ------------------- TRAVERSALS -------------------

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";      // Root
    preorder(root->left);           // Left
    preorder(root->right);          // Right
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);            // Left
    cout << root->data << " ";      // Root
    inorder(root->right);           // Right
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);          // Left
    postorder(root->right);         // Right
    cout << root->data << " ";      // Root
}

// ------------------- MAIN PROGRAM -------------------

int main() {
    // Creating a sample binary tree
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}
