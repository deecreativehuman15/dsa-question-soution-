#include <stdio.h>
#include <stdlib.h>

// Definition of the node of a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if two trees are identical
int areIdentical(struct Node* root1, struct Node* root2) {
    // If both trees are empty, they are identical
    if (root1 == NULL && root2 == NULL)
        return 1;

    // If both trees are non-empty, check if the data of the nodes is the same
    // and recursively check for left and right subtrees
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data &&
                areIdentical(root1->left, root2->left) &&
                areIdentical(root1->right, root2->right));
    }

    // If one tree is empty and the other is not, they are not identical
    return 0;
}

int main() {
    // Create two identical trees
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    // Check if the trees are identical
    if (areIdentical(root1, root2))
        printf("The two trees are identical.\n");
    else
        printf("The two trees are not identical.\n");

    return 0;
}
