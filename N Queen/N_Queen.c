#include <stdio.h>

int n, board[10][10];

void printSolution();
int isSafe(int row, int col);
int solveNQueen(int col);

void main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    // Initialize board with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    if (solveNQueen(0))
        printSolution();
    else
        printf("Solution does not exist.\n");
}

// Function to check if a queen can be placed at board[row][col]
int isSafe(int row, int col) {
    int i, j;

    // Check the left side of the row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Function to solve N-Queen using Backtracking
int solveNQueen(int col) {
    if (col >= n) // If all queens are placed
        return 1;

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1; // Place queen

            if (solveNQueen(col + 1)) // Recur to place rest of the queens
                return 1;

            board[i][col] = 0; // Backtrack
        }
    }

    return 0;
}

// Function to print the chessboard
void printSolution() {
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                printf("Q\t");
            else
                printf(".\t");
        }
        printf("\n");
    }
}
