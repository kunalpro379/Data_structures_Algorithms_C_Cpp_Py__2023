#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols = 4;

    // Declare a double pointer to int
    int** matrix;

    // Allocate memory for the rows (an array of int pointers)
    matrix = (int**)malloc(rows * sizeof(int*));

    // Check if memory allocation was successful
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each row (an array of ints)
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));

        // Check if memory allocation was successful
        if (matrix[i] == NULL) {
            printf("Memory allocation failed.\n");

            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);

            return 1;
        }
    }

    // Initialize and print the 2D array
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = count++;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Deallocate the memory for the 2D array
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
