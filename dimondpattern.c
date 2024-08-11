#include <stdio.h>

int main() {
    int n;

    // Get the number of rows for the diamond (the middle row will have 2n-1 stars)
    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &n);

    // Print the upper half of the diamond
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the lower half of the diamond
    for (int i = n ; i >= 1; i--) {
        // Print spaces
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
