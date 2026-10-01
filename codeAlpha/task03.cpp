#include <iostream>

using namespace std;

// Define the size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check for the Sudoku rules (row, column, and 3x3 subgrid constraints) before placing a number.
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if we find the same num in the similar row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check if we find the same num in the similar column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check if we find the same num in the particular 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Implement a backtracking algorithm to fill empty cells with valid numbers[cite: 5].
bool solveSudoku(int grid[N][N]) {
    int row = -1, col = -1;
    bool isEmpty = false;

    // Find an empty cell (represented by 0)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // No empty space left, puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Recursively try possible numbers until the puzzle is solved[cite: 5].
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            // Backtrack if the number doesn't lead to a solution
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Represent the Sudoku grid as a 2D array[cite: 5]. 
    // 0 represents empty cells.
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Unsolved Sudoku Grid:\n";
    printGrid(grid);
    cout << "\nSolving...\n\n";

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku Grid:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku grid." << endl;
    }

    return 0;
}