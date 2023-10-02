#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define the sparse matrices
    int sparse1[5][6] = {
        {0, 0, 0, 3, 0, 0},
        {0, 1, 0, 4, 0, 0},
        {0, 0, 0, 0, 0, 2},
        {1, 0, 3, 0, 0, 0},
        {0, 0, 0, 7, 0, 0}
    };

    int sparse2[5][6] = {
        {0, 4, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 6, 0, 0, 0, 9},
        {1, 0, 0, 0, 0, 0}
    };

    // Initialize an array to store triplet representation of sparse1
    int trip1[10][3];
    int con1 = 0; // Initialize a counter for the number of non-zero elements in sparse1

    // Convert sparse1 into triplet format
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (sparse1[i][j] != 0) {
                trip1[con1][0] = i; // Row index
                trip1[con1][1] = j; // Column index
                trip1[con1][2] = sparse1[i][j]; // Value
                con1++;
            }
        }
    }

    // Initialize an array to store triplet representation of sparse2
    int trip2[30][3];
    int con2 = 0; // Initialize a counter for the number of non-zero elements in sparse2

    // Convert sparse2 into triplet format
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (sparse2[i][j] != 0) {
                trip2[con2][0] = i; // Row index
                trip2[con2][1] = j; // Column index
                trip2[con2][2] = sparse2[i][j]; // Value
                con2++;
            }
        }
    }

    // Initialize an array to store the result of matrix multiplication
    int result[30][3];
    int res = 0; // Initialize a counter for the number of non-zero elements in the result

    // Perform matrix multiplication and store the result in triplet format
    for (int i = 0; i < con1; i++) {
        int row1 = trip1[i][0];
        int col1 = trip1[i][1];
        int value1 = trip1[i][2];

        for (int j = 0; j < con2; j++) {
            int row2 = trip2[j][0];
            int col2 = trip2[j][1];
            int value2 = trip2[j][2];

            if (col1 == row2) {
                result[res][0] = row1; // Row index
                result[res][1] = col2; // Column index
                result[res][2] += value1 * value2; // Multiplication of values
                res++;
            }
        }
    }

    // Print the result in triplet format
    for (int i = 0; i < res; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
