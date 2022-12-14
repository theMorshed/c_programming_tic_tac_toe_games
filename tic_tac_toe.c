#include <stdio.h>

void print_structure(int table[][4], int n);

int main()
{
    int n = 3, i, j;
    int table[4][4];
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            table[i][j] = -1;
        }
    }

    print_structure(table, n);

    return 0;
}

void print_structure(int table[][4], int n)
{
    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (table[i][j] == -1)
                printf(" ");
            if (j < n) 
                printf("\t|\t");
        }
        printf("\n");
        if (i < n) 
            printf("__________________________________");
        printf("\n\n");
    }
}