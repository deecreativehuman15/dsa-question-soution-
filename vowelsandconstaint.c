// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char str[100];
//     int vowels = 0, consonants = 0;

//     // Prompt the user to enter a string
//     printf("Enter a string: ");
//     fgets(str, sizeof(str), stdin);

//     // Iterate through each character of the string
//     for (int i = 0; str[i] != '\0'; i++) {
//         char ch = tolower(str[i]);  // Convert character to lowercase for easy comparison

//         // Check if the character is an alphabet letter
//         if (ch >= 'a' && ch <= 'z') {
//             // Check if it's a vowel
//             if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
//                 vowels++;
//             } else {
//                 consonants++;
//             }
//         }
//     }

//     // Display the counts
//     printf("Number of vowels: %d\n", vowels);
//     printf("Number of consonants: %d\n", consonants);

//     return 0;
// }
// ===================================================================================================
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;

    // Ask the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);  // Convert the character to lowercase

        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        }
        // Check if the character is a consonant (a letter that's not a vowel)
        else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }
    }

    // Print the number of vowels and consonants
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
