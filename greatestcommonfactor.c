#include <stdio.h>

// Function to find GCF using the Euclidean algorithm
int findGCF(int a, int b) {
    // Continue until one of the numbers becomes zero
    while (b != 0) {
        int temp = b;
        b = a % b;  // Get the remainder
        a = temp;   // Update a with the value of b
    }
    return a;  // a is the GCF
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Find the GCF of the two numbers
    int gcf = findGCF(num1, num2);

    // Display the result
    printf("The Greatest Common Factor of %d and %d is: %d\n", num1, num2, gcf);

    return 0;
}
