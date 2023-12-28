#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3;
    int cols = 4;

    int** mat;

    mat = (int**)malloc(rows * sizeof(int*));

    if (mat == NULL) {
  
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));

        if (mat[i] == NULL) {
      

            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);

            return 1;
        }
    }

    // Initialize and print the 2D array
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = count++;
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
