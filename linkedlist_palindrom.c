#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to find the middle of the linked list
struct Node* findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
int isPalindrome(struct Node* head) {
    if (!head || !head->next) return 1;  // A single node or empty list is a palindrome by default

    struct Node *middle = findMiddle(head);
    struct Node *secondHalf = reverseList(middle); // Reverse the second half of the list

    struct Node *firstHalf = head;
    struct Node *tempSecondHalf = secondHalf;

    // Compare the first half and the reversed second half
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data) {
            return 0; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Optional: Restore the list to its original form by reversing the second half again
    reverseList(tempSecondHalf);

    return 1; // The list is a palindrome
}

// Function to print the linked list (for debugging purposes)
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 2 -> 1
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);

    // Print the linked list
    printf("Original List: ");
    printList(head);

    // Check if the list is a palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
