#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int currentPlayer = 0;
    int number = 0;
    int choice;

    srand(time(0)); // set seed

    while (number < 30) {
        if (currentPlayer == 0) {
            printf("enter the number u want, 1 or 2:");
            scanf("%d", &choice);

            if (choice != 1 && choice != 2) {
                printf("wrong input. try again.\n");
                fflush(stdin);
                continue;
            }

            number += choice;
        } else {
            int remainder = number % 3; //

            if (remainder == 1) {
                choice = 1;
            } else if (remainder == 2) {
                choice = 2;
            } else {
                choice = rand() % 2 + 1;
            }

            printf("computer gives %d.\n", choice);
            number += choice;
        }

        printf("number now is %d.\n", number);
        currentPlayer = (currentPlayer + 1) % 2;
    }

    if (currentPlayer == 0) {
        printf("you win!\n");
    } else {
        printf("computer wins.\n");
    }

    return 0;
}
