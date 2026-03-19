#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number (0-2)
int generateRandomNumber() {
    return rand() % 3;
}

// Function to decide winner
int decideWinner(int player, int computer) {
    if (player == computer)
        return 0; // Draw
    if ((player == 0 && computer == 2) ||
        (player == 1 && computer == 0) ||
        (player == 2 && computer == 1))
        return 1; // Player wins
    return -1; // Computer wins
}

int main() {
    srand(time(NULL));

    char name[50];
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;

    char *choices[] = {"Rock", "Paper", "Scissor"};

    printf("\n====================================\n");
    printf("      ROCK PAPER SCISSOR GAME\n");
    printf("====================================\n");

    printf("Enter your name: ");
    scanf("%49s", name);

    printf("\nWelcome, %s!\n", name);
    printf("------------------------------------\n");
    printf("0 = Rock\n1 = Paper\n2 = Scissor\n");
    printf("------------------------------------\n");

    for (int round = 1; round <= 3; round++) {
        printf("\nRound %d\n", round);
        printf("%s, enter your choice: ", name);

        scanf("%d", &playerChoice);

        // Input validation
        if (playerChoice < 0 || playerChoice > 2) {
            printf("Invalid input! Try again.\n");
            round--;
            continue;
        }

        computerChoice = generateRandomNumber();

        printf("You chose: %s\n", choices[playerChoice]);
        printf("Computer chose: %s\n", choices[computerChoice]);

        int result = decideWinner(playerChoice, computerChoice);

        if (result == 0) {
            printf("It's a DRAW!\n");
        } else if (result == 1) {
            printf("%s wins this round!\n", name);
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        printf("Score -> %s: %d | Computer: %d\n", name, playerScore, computerScore);
        printf("\n____________________________________\n");
    }

    printf("\n====================================\n");
    printf("           FINAL RESULT\n");
    printf("====================================\n");

    printf("%s: %d | Computer: %d\n", name, playerScore, computerScore);

    if (playerScore > computerScore) {
        printf("%s wins the game!\n", name);
    } else if (computerScore > playerScore) {
        printf("Computer wins the game!\n");
    } else {
        printf("The game is a DRAW!\n");
    }

    printf("====================================\n");

    return 0;
}