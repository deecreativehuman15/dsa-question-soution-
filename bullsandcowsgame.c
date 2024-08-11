#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateNumber(char *number) {
    int digit, i;
    char temp;

    for (i = 0; i < 4; i++) {
        do {
            digit = rand() % 10;
            temp = '0' + digit;
        } while (strchr(number, temp) != NULL);
        number[i] = temp;
    }
    number[4] = '\0';
}

void evaluateGuess(char *number, char *guess, int *bulls, int *cows) {
    int i, j;
    *bulls = 0;
    *cows = 0;

    for (i = 0; i < 4; i++) {
        if (guess[i] == number[i]) {
            (*bulls)++;
        } else {
            for (j = 0; j < 4; j++) {
                if (guess[i] == number[j] && i != j) {
                    (*cows)++;
                    break;
                }
            }
        }
    }
}

int main() {
    char number[5];
    char guess[5];
    int bulls, cows;
    int attempts = 0;

    srand(time(0));

    generateNumber(number);

    printf("Welcome to Bulls and Cows!\n");
    printf("Guess the 4-digit number. Each digit is unique.\n");

    do {
        printf("Enter your guess: ");
        scanf("%4s", guess);

        if (strlen(guess) != 4) {
            printf("Please enter exactly 4 digits.\n");
            continue;
        }

        evaluateGuess(number, guess, &bulls, &cows);
        attempts++;

        if (bulls == 4) {
            printf("Congratulations! You've guessed the number in %d attempts.\n", attempts);
            break;
        } else {
            printf("Bulls: %d, Cows: %d\n", bulls, cows);
        }
    } while (1);

    return 0;
}
