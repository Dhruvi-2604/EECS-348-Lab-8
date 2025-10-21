/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

/*
 * Program for EECS 348 Lab 8, Task 1: Football Score Possibilities
 * Determines all possible combinations of NFL scoring plays that result in a given score.
 */

// Define point values for scoring plays
#define TD_2PT 8    // Touchdown + 2-point conversion
#define TD_FG 7     // Touchdown + 1-point field goal
#define TD 6        // Touchdown (without conversion)
#define FG 3        // Field goal
#define SAFETY 2    // Safety

void find_combinations(int score) {
    // Nested loops for each scoring play type. The loop limit is (score / points) + 1
    // to ensure all possible counts (from 0 up to the maximum possible) are checked.
    
    int c8, c7, c6, c3, c2; // Counters for each scoring play's point value

    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    // c8: TD + 2pt (8 points)
    for (c8 = 0; c8 * TD_2PT <= score; c8++) {
        // c7: TD + FG (7 points)
        for (c7 = 0; c7 * TD_FG + c8 * TD_2PT <= score; c7++) {
            // c6: TD (6 points)
            for (c6 = 0; c6 * TD + c7 * TD_FG + c8 * TD_2PT <= score; c6++) {
                // c3: Field Goal (3 points)
                for (c3 = 0; c3 * FG + c6 * TD + c7 * TD_FG + c8 * TD_2PT <= score; c3++) {
                    // c2: Safety (2 points)
                    // The count for Safeties is directly calculated, as 2 is the lowest
                    // common point value and an easy remainder to check.
                    int current_total = c8 * TD_2PT + c7 * TD_FG + c6 * TD + c3 * FG;
                    int remaining = score - current_total;
                    
                    // Check if the remaining points are a multiple of 2 (Safety points)
                    if (remaining >= 0 && remaining % SAFETY == 0) {
                        c2 = remaining / SAFETY;

                        // Print the valid combination
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                               c8, c7, c6, c3, c2);
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    // The program should repeatedly prompt the user and terminate only when 1 is entered.
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            // Handle non-integer input
            printf("Invalid input. Please enter an integer.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        if (score == 1) {
            printf("Program terminated.\n");
            break;
        } else if (score < 2) {
            // Scores 0 and 1 are impossible except for the stop condition
            printf("A score of %d is not possible with NFL scoring plays (min score is 2 for a Safety).\n", score);
        } else {
            find_combinations(score);
        }
    }

    return 0;
}