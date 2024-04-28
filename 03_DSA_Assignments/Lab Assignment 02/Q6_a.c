#include <stdio.h>
#include <stdlib.h>

int main() {
    int sparse[5][6] = {
        {0, 0, 0, 3, 0, 0},
        {0, 1, 0, 4, 0, 0},
        {0, 0, 0, 0, 0, 2},
        {1, 0, 3, 0, 0, 0},
        {0, 0, 0, 7, 0, 0}
    };

    int trans[6][5]; // Initialize a matrix to store the transpose

    // Transpose the sparse matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            trans[j][i] = sparse[i][j];
        }
    }

    // Count the number of non-zero elements in the transpose
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (trans[i][j] != 0) {
                sum++;
            }
        }
    }

    // Create an array to store the non-zero elements with their positions
    int s[sum][3];
    int k = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (trans[i][j] != 0) {
                s[k][0] = i; // Row index
                s[k][1] = j; // Column index
                s[k][2] = trans[i][j]; // Value
                k++;
            }
        }
    }

    // Print the non-zero elements in the format: row, column, value
    for (int i = 0; i < sum; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}
