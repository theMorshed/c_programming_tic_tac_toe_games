#include <stdio.h>
#include <stdbool.h>

// print structure function prototype
void print_structure(int table[][4], int n);

int main()
{
    // declare necessary variable
    int n = 3, i, j;
    int table[4][4];
    bool player_one = true, player_two = false;

    // initialize -1 in whole matrix or 2d array
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            table[i][j] = -1;
        }
    }

    // control player turn and print the struture
    while (true) {
        print_structure(table, n);
        if (player_one == true) { // player one turn 
            int row, col;
            printf("Player 1 turn(X), Enter row and column: ");
            scanf("%d %d", &row, &col);
            if (table[row][col] != -1) {
                printf("Invalid Cell\n");
                continue;
            }
            table[row][col] = 1;

            player_one = false;
            player_two = true;
        } else { // player two turn 
            int row, col;
            printf("Player 2 turn(O), Enter row and column: ");
            scanf("%d %d", &row, &col);
            if (table[row][col] != -1) {
                printf("Invalid Cell\n");
                continue;
            }
            table[row][col] = 2;

            player_two = false;
            player_one = true;
        }
    }

    return 0;
}

// print structure function declaration
void print_structure(int table[][4], int n)
{
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (table[i][j] == -1)
                printf(" ");
            else if (table[i][j] == 1)
                printf("X");
            else if (table[i][j] == 2) 
                printf("O");

            if (j < n) 
                printf("\t|\t");
        }
        printf("\n");
        if (i < n) 
            printf("__________________________________");
        printf("\n\n");
    }
}