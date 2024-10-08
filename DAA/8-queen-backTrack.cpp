#include <iostream>
using namespace std;

const int N = 4;

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col)
{
    // Check this row on the left side
    for (int x = 0; x < col; x++)
        if (board[row][x] == 1)
            return false;

    // Check upper diagonal on the left side
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
        if (board[x][y] == 1)
            return false;

    // Check lower diagonal on the left side
    for (int x = row, y = col; x < N && y >= 0; x++, y--)
        if (board[x][y] == 1)
            return false;

    return true;
}

// Solve the N-Queen problem
bool solveNQueens(int board[N][N], int col)
{
    if (col == N)
    {
        // Print the solution
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return true;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            // Place queen at board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1))
                return true;

            // If placiwhwhng queen at board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int board[N][N] = {0}; // Initialize board with 0s

    if (!solveNQueens(board, 0))
        cout << "No solution found";

    return 0;
}
