#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to search for a node with a given value in the binary tree
int search(struct Node* root, int value) {
    // Base case: if the root is NULL or the node with the value is found
    if (root == NULL) {
        return 0; // Node not found
    }
    if (root->data == value) {
        return 1; // Node found
    }

    // Recursively search in the left and right subtrees
    int foundInLeftSubtree = search(root->left, value);
    if (foundInLeftSubtree) {
        return 1;
    }
    
    return search(root->right, value);
}

int main() {
    // Create a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int valueToSearch = 5;

    // Search for the node in the binary tree
    if (search(root, valueToSearch)) {
        printf("Node with value %d found in the binary tree.\n", valueToSearch);
    } else {
        printf("Node with value %d not found in the binary tree.\n", valueToSearch);
    }

    return 0;
}
