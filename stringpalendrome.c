#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reversedStr[100];
    int length, i, j;

    // User ko ek string enter karne ke liye kehna
    printf("Enter a string: ");
    gets(str);

    // String ki length nikalna
    length = strlen(str);

    // Nested loop to reverse the string
    for (i = 0; i < length; i++) {
        // Inner loop to find the correct character from the end of the string
        for (j = length - 1; j >= 0; j--) {
            if (j == length - 1 - i) {
                reversedStr[i] = str[j];
                break;  // Found the matching character for this position, exit inner loop
            }
        }
    }
    reversedStr[length] = '\0'; // Reversed string ko end karne ke liye null character

    // Compare karna agar original string aur reversed string same hain
    if (strcmp(str, reversedStr) == 0)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}
