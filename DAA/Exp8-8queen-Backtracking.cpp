#include <stdio.h>
#include <stdbool.h>
#define MAX 20

// Function to print the board
void printBoard(int board[MAX][MAX], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
// Check if a queen can be placed on board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int N)
{
    // Check this column on all rows above this row
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
// Solve the N-Queens problem using backtracking
bool solveNQueens(int board[MAX][MAX], int row, int N)
{
    if (row == N)
    {

        return true; // All queens are placed
    }

    // Try all columns for the current row
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1; // Place queen

            // Recur to place queen in the next row
            if (solveNQueens(board, row + 1, N))
            {
                return true;
            }

            // Backtrack: remove queen
            board[row][col] = 0;
        }
    }

    return false; // If no place is found, return false
}

int main()
{
    int N;
    printf("Enter the number of queens: ");
    scanf("%d", &N);

    int board[MAX][MAX] = {0}; // Initialize the board to 0

    if (solveNQueens(board, 0, N))
    {
        printBoard(board, N);
    }
    else
    {
        printf("Solution does not exist.\n");
    }

    return 0;
}