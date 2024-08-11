#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256  // Define the size of the ASCII character set

// Function to find the maximum frequency of a character in a string
char findMaxFrequencyChar(char *str) {
    int count[ASCII_SIZE] = {0};  // Initialize an array to count the frequency of each character
    int max = 0;  // To store the maximum frequency
    char maxChar = '\0';  // To store the character with the maximum frequency

    // Count the frequency of each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        count[(int)str[i]]++;
    }

    // Find the character with the maximum frequency
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (count[i] > max) {
            max = count[i];
            maxChar = (char)i;
        }
    }

    return maxChar;
}

int main() {
    char str[100];

    // Input a string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Find and print the character with the maximum frequency
    char maxChar = findMaxFrequencyChar(str);
    printf("The character with the maximum frequency is '%c'.\n", maxChar);

    return 0;
}
