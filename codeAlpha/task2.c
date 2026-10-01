#include <stdio.h>

#define MAX 10 // Maximum size for matrix dimensions to keep it simple

// Function Prototypes
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]);
void displayMatrix(int rows, int cols, int matrix[MAX][MAX]);
void addMatrices(int rows, int cols, int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX]);
void multiplyMatrices(int r1, int c1, int mat1[MAX][MAX], int r2, int c2, int mat2[MAX][MAX], int result[MAX][MAX]);
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]);

int main() {
    int choice;
    int r1, c1, r2, c2;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];

    printf("--- Matrix Operations Menu ---\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            printf("Enter rows and columns for matrices (e.g., 2 2): ");
            scanf("%d %d", &r1, &c1);
            r2 = r1; c2 = c1; // For addition, dimensions must be the same

            printf("Enter elements of Matrix 1:\n");
            inputMatrix(r1, c1, mat1);
            printf("Enter elements of Matrix 2:\n");
            inputMatrix(r2, c2, mat2);

            addMatrices(r1, c1, mat1, mat2, result);
            
            printf("\nResult of Matrix Addition:\n");
            displayMatrix(r1, c1, result);
            break;

        case 2: // Multiplication
            printf("Enter rows and columns for Matrix 1: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns for Matrix 2: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Error: Multiplication not possible. Column of Mat1 must equal Row of Mat2.\n");
            } else {
                printf("Enter elements of Matrix 1:\n");
                inputMatrix(r1, c1, mat1);
                printf("Enter elements of Matrix 2:\n");
                inputMatrix(r2, c2, mat2);

                multiplyMatrices(r1, c1, mat1, r2, c2, mat2, result);
                
                printf("\nResult of Matrix Multiplication:\n");
                displayMatrix(r1, c2, result);
            }
            break;

        case 3: // Transpose
            printf("Enter rows and columns for the Matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter elements of the Matrix:\n");
            inputMatrix(r1, c1, mat1);

            transposeMatrix(r1, c1, mat1, result);
            
            printf("\nTransposed Matrix:\n");
            displayMatrix(c1, r1, result); // Notice the inverted rows and cols
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// Function to input elements into a matrix
void inputMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void displayMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int r1, int c1, int mat1[MAX][MAX], int r2, int c2, int mat2[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize cell to 0 before accumulation
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}