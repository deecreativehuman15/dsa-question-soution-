#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to check if a node is a leaf
bool isLeaf(struct Node* node) {
    return (node->left == NULL && node->right == NULL);
}

// DFS function to check if all leaf nodes are at the same level
bool checkLeavesLevel(struct Node* root, int level, int* leafLevel) {
    if (root == NULL) return true;

    // If the node is a leaf node
    if (isLeaf(root)) {
        // If it's the first leaf node, record its level
        if (*leafLevel == -1) {
            *leafLevel = level;
        }
        // Compare the level of the current leaf node with the first leaf's level
        return level == *leafLevel;
    }

    // Recursively check left and right subtrees
    return checkLeavesLevel(root->left, level + 1, leafLevel) &&
           checkLeavesLevel(root->right, level + 1, leafLevel);
}

// Wrapper function to initiate the DFS check
bool areAllLeavesAtSameLevel(struct Node* root) {
    int leafLevel = -1;
    return checkLeavesLevel(root, 0, &leafLevel);
}

// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->left->left->left = newNode(7);

    if (areAllLeavesAtSameLevel(root)) {
        printf("All leaf nodes are at the same level.\n");
    } else {
        printf("All leaf nodes are NOT at the same level.\n");
    }

    return 0;
}
