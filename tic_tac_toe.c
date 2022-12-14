#include <stdio.h>
#include <stdbool.h>

// print structure function prototype
void print_structure(int table[][4], int n);
int who_is_win(int table[][4], int n);

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

        // check who is win
        if (who_is_win(table, n) == 1) {
            printf("Player 1 is Won!\n");
            print_structure(table, n);
            break;
        } else if (who_is_win(table, n) == 2) {
            printf("Player 2 is Won!\n");
            print_structure(table, n);
            break;
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

int who_is_win(int table[][4], int n)
{
    for (int i = 1; i <= 3; i++) {
        if (table[i][1] == table[i][2] && table[i][2] == table[i][3] && table[i][1] != -1) {
            return table[i][1];
        }
    }

    for (int j = 1; j <= 3; j++) {
        if (table[1][j] == table[2][j] && table[2][j] == table[3][j] && table[1][j] != -1) {
            return table[1][j];
        }
    }

    if (table[1][1] == table[2][2] && table[2][2] == table[3][3] && table[1][1] != -1) {
        return table[1][1];
    }

    if (table[1][3] == table[2][2] && table[2][2] == table[3][1] && table[1][3] != -1) {
        return table[1][3];
    }
    
    return -1;
}